//
//  MLAudioPlayerManager.swift
//  MLAndes
//
//  Created by Mac on 2026/5/21.
//

import AVFoundation

// MARK: - TimeInterval Extension
extension TimeInterval {
    /// Format as MM:SS
    var toMMSS: String {
        let minutes = Int(self) / 60
        let seconds = Int(self) % 60
        return String(format: "%02d:%02d", minutes, seconds)
    }
    
    /// Format as HH:MM:SS (used when the duration is over an hour)
    var toHHMMSS: String {
        let hours = Int(self) / 3600
        let minutes = (Int(self) % 3600) / 60
        let seconds = Int(self) % 60
        
        if hours > 0 {
            return String(format: "%02d:%02d:%02d", hours, minutes, seconds)
        } else {
            return String(format: "%02d:%02d", minutes, seconds)
        }
    }
}

class MLAudioPlayerManager: NSObject {
    private var audioPlayer: AVAudioPlayer?
    private var progressTimer: Timer?
    
    // Total audio duration
    var totalDuration: TimeInterval {
        return audioPlayer?.duration ?? 0
    }
    
    // Formatted total duration
    var totalDurationText: String {
        return totalDuration.toMMSS
    }
    
    // Current playback position
    var currentTime: TimeInterval {
        get { return audioPlayer?.currentTime ?? 0 }
        set {
            audioPlayer?.currentTime = newValue
            // Call back immediately when set
            onProgressUpdate?(currentTime)
        }
    }
    
    // Formatted current position
    var currentTimeText: String {
        return currentTime.toMMSS
    }
    
    // Formatted remaining time
    var remainingTimeText: String {
        let remaining = totalDuration - currentTime
        return remaining.toMMSS
    }
    
    // Progress text (current / total)
    var progressText: String {
        return "\(currentTimeText) / \(totalDurationText)"
    }
    
    // Whether audio is playing
    var isPlaying: Bool {
        return audioPlayer?.isPlaying ?? false
    }
    
    // Playback progress (0-1)
    var progress: Float {
        guard totalDuration > 0 else { return 0 }
        return Float(currentTime / totalDuration)
    }
    
    // Playback-finished callback
    var finishedBlock: (() -> Void)?
    
    // Live progress callback (several times a second)
    var onProgressUpdate: ((TimeInterval) -> Void)?
    
    override init() {
        super.init()
        setupAudioSession()
    }
    
    deinit {
        stopProgressMonitoring()
    }
    
    // MARK: - Audio Session Setup
    private func setupAudioSession() {
        do {
            // Configure the audio session
            try AVAudioSession.sharedInstance().setCategory(.playback, mode: .default)
            try AVAudioSession.sharedInstance().setActive(true)
        } catch {
            print("Failed to set audio session: \(error)")
        }
    }
    
    // MARK: - Load Audio
    // Load an audio file
    func loadAudio(url: URL) -> Bool {
        do {
            audioPlayer = try AVAudioPlayer(contentsOf: url)
            audioPlayer?.prepareToPlay()
            audioPlayer?.delegate = self
            return true
        } catch {
            print("Failed to load audio: \(error)")
            return false
        }
    }
    
    // Load from the app bundle
    func loadAudioFromBundle(fileName: String, fileExtension: String) -> Bool {
        guard let url = Bundle.main.url(forResource: fileName, withExtension: fileExtension) else {
            print("Audio file not found")
            return false
        }
        return loadAudio(url: url)
    }
    
    // MARK: - Playback Control
    // Play
    func play() {
        audioPlayer?.play()
        startProgressMonitoring()
    }
    
    // Pause
    func pause() {
        audioPlayer?.pause()
        stopProgressMonitoring()
    }
    
    // Stop and rewind to the start
    func stop() {
        audioPlayer?.stop()
        audioPlayer?.currentTime = 0
        stopProgressMonitoring()
        onProgressUpdate?(0)
    }
    
    // Seek to a time
    func seek(to time: TimeInterval) {
        audioPlayer?.currentTime = max(0, min(time, totalDuration))
        onProgressUpdate?(currentTime)
    }
    
    // Set playback progress (0-1)
    func setProgress(_ progress: Float) {
        let time = TimeInterval(progress) * totalDuration
        seek(to: time)
    }
    
    // MARK: - Progress Monitoring
    private func startProgressMonitoring() {
        stopProgressMonitoring()
        progressTimer = Timer.scheduledTimer(timeInterval: 0.1,
                                             target: self,
                                             selector: #selector(updateProgress),
                                             userInfo: nil,
                                             repeats: true)
        RunLoop.current.add(progressTimer!, forMode: .common)
    }
    
    private func stopProgressMonitoring() {
        progressTimer?.invalidate()
        progressTimer = nil
    }
    
    @objc private func updateProgress() {
        guard isPlaying else { return }
        onProgressUpdate?(currentTime)
    }
}

// MARK: - AVAudioPlayerDelegate
extension MLAudioPlayerManager: AVAudioPlayerDelegate {
    func audioPlayerDidFinishPlaying(_ player: AVAudioPlayer, successfully flag: Bool) {
        if flag {
            print("Playback finished")
            stopProgressMonitoring()
            finishedBlock?()
            onProgressUpdate?(totalDuration)
        }
    }
    
    func audioPlayerDecodeErrorDidOccur(_ player: AVAudioPlayer, error: Error?) {
        print("Decode error: \(error?.localizedDescription ?? "unknown error")")
        stopProgressMonitoring()
    }
}
