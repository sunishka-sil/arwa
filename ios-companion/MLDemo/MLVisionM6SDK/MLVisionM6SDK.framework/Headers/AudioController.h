
#import <Foundation/Foundation.h>

#define DEBUG_MODE
#ifdef DEBUG_MODE
#define TLog( s, ... ) NSLog( s, ##__VA_ARGS__ )
#else
#define TLog( s, ... )
#endif

/**
 *@discuss AudioController callback interfaces
 */
@protocol ConvVoiceRecorderDelegate <NSObject>

/**
 * @discuss Recorder started; called on the main thread
 */
-(void) recorderDidStart;

/**
 * @discuss Recorder stopped; called on the main thread
 */
-(void) recorderDidStop;

/**
 * @discuss Recorder captured data. This usually involves VAD, compression and so on, so to avoid blocking the main thread it is called on the AudioQueue thread. Mind thread safety!
 */
-(void) voiceRecorded:(unsigned char*)buffer Length:(int)len;

/**
 *@discussion Called when the recorder can't be opened or another error occurs
 */
-(void) voiceDidFail:(NSError*)error;


/**
 * @Player playback started
 */
-(void) playerDidStart;

/**
 * @Player finished draining data; called synchronously
 */
-(void) playerDrainDataFinish;

/**
 * @Player finished playing data
 */
-(void) playerDidFinish;

/**
 * @Player volume level callback, 0-100
 */
-(void) playSoundLevel:(int)level;

/// Playback data callback
-(void) playData:(unsigned char*)buffer Length:(int)len;

@end

/**
 *@discuss Recorder and player built on the AudioUnit C API
 */
@interface AudioController : NSObject

/// Recording event delegate
@property(nonatomic,assign) id<ConvVoiceRecorderDelegate> delegate;

/// Current volume level
@property(nonatomic,readonly) NSUInteger currentVoiceVolume;

/**
 * Start recording
 */
-(void)startRecorder;

/**
 * Stop recording
 */
-(void)stopRecorder:(BOOL)shouldNotify;

/**
 *  Mute the recorder
 */
-(void)mute;

/**
 *  Unmute the recorder
 */
-(void)unmute;

/**
 * Whether recording is in progress
 */
-(BOOL)isRecorderStarted;

/**
 * Start playback
 */
-(void)startPlayer;

/**
 * Stop playback
 */
-(void)stopPlayer;

/**
 * Write PCM audio data to the player
 */
-(int)write:(const char*)buffer Length:(int)len;

/**
 * Set the player's sample rate
 */
-(void)setPlayerSampleRate :(int)sr;

/**
 * Whether the player is draining
 */
-(bool)checkPlayerFinish;

/**
 * Clear buffered data and the hardware player's data
 */
-(void)cleanPlayerBuffer;

/**
 * Tell the player all data has been written; then wait for playback to finish
 */
-(void)drain;

/**
 * Whether playback has stopped
 */
-(BOOL)isPlayerStopped;

/**
 *  Volume calculation
 */
-(int)calculateVolumeFromPCMData:(unsigned char*)cal_buffer Size:(unsigned int)size Offset:(unsigned int)offset Add:(unsigned char*)add_buffer Length:(unsigned int)len;


@end
