//
//  MLAssistantOC.swift
//  MLVisionSDK_Example
//
//  Created by lijuan on 5/22/25.
//  Copyright © 2025 CocoaPods. All rights reserved.
//

import UIKit
import MLVisionM6SDK

class MLiflyaManager: NSObject {
    
    static let shared = MLiflyaManager()
    lazy var aiuiAgent: IFlyAIUIAgent = {
        let cfgFilePath = Bundle.main.path(forResource: "aiui", ofType: "cfg")
        let cfg = try! String(contentsOfFile: cfgFilePath ?? "", encoding: .utf8)
        return IFlyAIUIAgent.createAgent(cfg, withListener: self)
         
    }()
    var ttsStatus = 2
    var iflyrecognize = IFlySpeechRecognizer.sharedInstance()

    override init() {
        super.init()
        IFlySpeechUtility.createUtility("appid=3e1371f0")
    }

    func initAIUI(sn:String?){
        if let sn = sn{

            IFlyAIUISetting.setSaveDataLog(false)
            IFlyAIUISetting.setLogLevel(.LV_INFO)
            let path = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)
            let cachePath = path.first?.appending("/")
            IFlyAIUISetting.setAIUIDir(cachePath)
            IFlyAIUISetting.setMscCfg(cachePath)
            IFlyAIUISetting.setSystemInfo("sn",withVal: sn)
            let cfgFilePath = Bundle.main.path(forResource: "aiui", ofType: "cfg")
            let cfg = try! String(contentsOfFile: cfgFilePath ?? "", encoding: .utf8)
            aiuiAgent = IFlyAIUIAgent.createAgent(cfg, withListener: self)
        }
        iflyrecognize?.setParameter("iat", forKey: IFlySpeechConstant.ifly_DOMAIN())
        iflyrecognize?.setParameter("iat.pcm", forKey: IFlySpeechConstant.asr_AUDIO_PATH())
        iflyrecognize?.delegate = self
    }
    
    func initIflyRecognize(){
        iflyrecognize = IFlySpeechRecognizer.sharedInstance()
        iflyrecognize?.setParameter("iat", forKey: IFlySpeechConstant.ifly_DOMAIN())
        iflyrecognize?.setParameter("iat.pcm", forKey: IFlySpeechConstant.asr_AUDIO_PATH())
        iflyrecognize?.delegate = self
    }
    
    
}

// Result callback
// Implements the IFlyAIUIListener protocol; results arrive in the onEvent callback.
@available(iOS 15.0, *)
extension MLiflyaManager:IFlyAIUIListener{
    
    func onEvent(_ event: IFlyAIUIEvent!) {
        
        switch event.eventType {
        case Int32(AIUI_EVENT_TYPE.EVENT_CONNECTED_TO_SERVER.rawValue):
            MLVisionM6SDKManager.handleIflyEvent(Int(AIUI_EVENT_TYPE.EVENT_CONNECTED_TO_SERVER.rawValue))
            break
        case Int32(AIUI_EVENT_TYPE.EVENT_SERVER_DISCONNECTED.rawValue):
            // Server disconnected
            MLVisionM6SDKManager.handleIflyEvent(Int(AIUI_EVENT_TYPE.EVENT_SERVER_DISCONNECTED.rawValue))
            break
        case Int32(AIUI_EVENT_TYPE.EVENT_START_RECORD.rawValue):
            // Recording started
            break
        case Int32(AIUI_EVENT_TYPE.EVENT_STOP_RECORD.rawValue):
            // Recording stopped
            break
        case Int32(AIUI_EVENT_TYPE.EVENT_STATE.rawValue):
            // AIUI state changed
            
            switch event.arg1 {
            case Int32(AIUI_STATE_TYPE.STATE_IDLE.rawValue):
                print("ble-handleAssistant:Assistant:STATE_IDLE")
                break
            case Int32(AIUI_STATE_TYPE.STATE_READY.rawValue):
                print("ble-handleAssistant:Assistant:STATE_READY")
                break
            case Int32(AIUI_STATE_TYPE.STATE_WORKING.rawValue):
                print("ble-handleAssistant:Assistant:STATE_WORKING")

                MLVisionM6SDKManager.handleIflyEvent(Int(AIUI_STATE_TYPE.STATE_WORKING.rawValue))

                break
            default:break
            }
        case Int32(AIUI_EVENT_TYPE.EVENT_WAKEUP.rawValue):
            MLVisionM6SDKManager.handleIflyEvent(Int(AIUI_EVENT_TYPE.EVENT_WAKEUP.rawValue))
            print("ble-handleAssistant:Assistant:EVENT_WAKEUP")

            break
        case Int32(AIUI_EVENT_TYPE.EVENT_SLEEP.rawValue):
            MLVisionM6SDKManager.handleIflyEvent(Int(AIUI_EVENT_TYPE.EVENT_SLEEP.rawValue))
            print("ble-handleAssistant:Assistant:EVENT_SLEEP")

            break
        case Int32(AIUI_EVENT_TYPE.EVENT_VAD.rawValue):
            switch event.arg1 {
                //                AIUI_VAD.VAD_BOS.rawValue
            case 0:
                //VAD_BOS
                // Speech start point (VAD begin)
                break
                
            case Int32(AIUI_VAD.VAD_EOS.rawValue):
                // Speech end point (VAD end)
                break
            case Int32(AIUI_VAD.VAD_VOL.rawValue):
                // Volume
                break
            default:
                break
            }
        case Int32(AIUI_EVENT_TYPE.EVENT_TTS.rawValue):
            processTTS(event: event)
            break
        case Int32(AIUI_EVENT_TYPE.EVENT_RESULT.rawValue):
            processResult(event: event)
            break
        case Int32(AIUI_EVENT_TYPE.EVENT_CMD_RETURN.rawValue): break
        case Int32(AIUI_EVENT_TYPE.EVENT_ERROR.rawValue):
            MLVisionM6SDKManager.handleIflyEvent(Int(AIUI_EVENT_TYPE.EVENT_ERROR.rawValue))
            print("ble-handleAssistant:EVENT_ERROR \(event.info) \(event.arg1)")
            MLVisionM6SDKManager.showErrorLog("ble-handleAssistant:EVENT_ERROR \(event.info) \(event.arg1)")

            break
            
        default:
            break
        }
        
    }
    func processTTS(event:IFlyAIUIEvent){
        MLVisionM6SDKManager.handleIflyTTSEvent(Int(event.arg1))

    }
    
    // Handle results
    func processResult(event:IFlyAIUIEvent){
        
        MLVisionM6SDKManager.handleIflyData(event.info, eventData: event.data)
        
    }
    
}


extension MLiflyaManager:MLVisonIflyProtocol{
    func startSend(_ data: Data) {
        let params = "data_type=audio,sample_rate=16000"
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_WRITE.rawValue)
        msg.data = data
        msg.params = params
        aiuiAgent.send(msg)
    }
    
    
    // Semantic understanding example
    // Send CMD_WAKEUP to AIUI. (The original comment says this puts AIUI to sleep; CMD_WAKEUP normally wakes it.)
    func sendSleepMsg(){
        
        let wakeUpMsg = IFlyAIUIMessage()
        wakeUpMsg.msgType = Int32(AIUI_CMD_TYPE.CMD_RESET_WAKEUP.rawValue)
        aiuiAgent.send(wakeUpMsg)
    }
    

    
    func ttsPlay(_ tts:String,speed:Int = 50){
        
        if tts.count == 0{
            return
        }
        let ttsData = tts.data(using: .utf8)
        
        let params = String(format: "vcn=x2_xiaojuan,speed=%d,pitch=50,volume=50",speed)
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_TTS.rawValue)
        msg.arg1 = Int32(AIUI_TTS_CTL.TTS_START.rawValue)
        msg.params = params
        msg.data = ttsData
        aiuiAgent.send(msg)
    }
    
    func ttsPause(){
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_TTS.rawValue)
        msg.arg1 = Int32(AIUI_TTS_CTL.TTS_PAUSE.rawValue)
        aiuiAgent.send(msg)
    }
    
    func ttsResume(){
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_TTS.rawValue)
        msg.arg1 = Int32(AIUI_TTS_CTL.TTS_RESUME.rawValue)
        aiuiAgent.send(msg)
    }
    
    func ttsStop(){
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_TTS.rawValue)
        msg.arg1 = Int32(AIUI_TTS_CTL.TTS_CANCEL.rawValue)
        aiuiAgent.send(msg)
    }
    
    func startRecord(){
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_START_RECORD.rawValue)
        aiuiAgent.send(msg)
    }
    
    func stopRecord(){
        
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_STOP_RECORD.rawValue)
        aiuiAgent.send(msg)
    }
    
    func stopSendData(){
        let msg:IFlyAIUIMessage = IFlyAIUIMessage()
        msg.msgType = Int32(AIUI_CMD_TYPE.CMD_STOP_WRITE.rawValue)
        aiuiAgent.send(msg)
    }
    
    func sendWakeUpMsg(_ sn: String) {
        initAIUI(sn:sn)
        let wakeUpMsg = IFlyAIUIMessage()
        wakeUpMsg.msgType = Int32(AIUI_CMD_TYPE.CMD_WAKEUP.rawValue)
        aiuiAgent.send(wakeUpMsg)
    }
    
    func cancelListening() {
        iflyrecognize?.cancel()
    }
    
    func destroyListening() {
        iflyrecognize?.destroy()
    }
    
    
    func startListning() {
        iflyrecognize?.startListening()

    }
    
    func stopListening() {
        iflyrecognize?.stopListening()
    }
    
    
    func initIflySDK(_ sn: String) {
        initAIUI(sn: sn)
    }
    
}
extension MLiflyaManager:IFlySpeechRecognizerDelegate{
    func onCompleted(_ errorCode: IFlySpeechError!) {
        if !iflyrecognize!.isListening{
            iflyrecognize?.startListening()
        }
    }
    
    func onResults(_ results: [Any]!, isLast: Bool) {
        print("result:\(results)")
        MLVisionM6SDKManager.handleIflyRecognizeData(results, isLast: isLast)
    }
    
}
