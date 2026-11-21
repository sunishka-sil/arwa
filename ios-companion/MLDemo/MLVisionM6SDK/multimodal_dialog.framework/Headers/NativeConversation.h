#ifndef NativeConversation_h
#define NativeConversation_h

#ifdef DEBUG_MODE
#define TLog( s, ... ) NSLog( s, ##__VA_ARGS__ )
#else
#define TLog( s, ... )
#endif

#import <Foundation/Foundation.h>
#import <multimodal_dialog/ConversationCode.h>

typedef int ConversationResultCode;

enum ConvEventType {
    EVENT_UNKNOWN = -1,
    EVENT_CONVERSATION_CONNECTED = 0,
    EVENT_CONVERSATION_INITIALIZED = 1,
    EVENT_CONVERSATION_STARTED,
    EVENT_CONVERSATION_FAILED,
    EVENT_CONVERSATION_COMPLETED,
    EVENT_DATA_OUTPUT_STARTED,
    EVENT_DATA_OUTPUT_COMPLETED,
    EVENT_SENTENCE_BEGIN,
    EVENT_SENTENCE_FINAL,  // mean EVENT_SENTENCE_END
    EVENT_INTERRUPT_ACCEPTED,
    EVENT_INTERRUPT_DENIED,
    EVENT_VOICE_INTERRUPT_ACCEPTED,
    EVENT_VOICE_INTERRUPT_DENIED,
    EVENT_HUMAN_SPEAKING_DETAIL = 13,
    EVENT_RESPONDING_DETAIL,
    EVENT_KEYWORD_SPOTTED = 15,
    EVENT_KEYWORD_TRUSTED,
    EVENT_VOICE_TIMEOUT,
    EVENT_OTHER_MESSAGE = 29,
    /* 以下为请求转换的事件 */
    EVENT_REQUEST_START = 30,
    EVENT_REQUEST_STOP,
    EVENT_SEND_SPEECH,
    EVENT_STOP_SPEECH,
    EVENT_REQUEST_TO_SPEAK,
    EVENT_REQUEST_TO_RESPOND,
    EVENT_LOCAL_RESPONDING_STARTED,
    EVENT_LOCAL_RESPONDING_ENDED,
    EVENT_AVATAR_STATE_CHANGED,
};

enum ConvStateType {
    DIALOG_STATE = 0,
    CONNECTION_STATE,
    INTERRUPTION_POLICY,
    MIC_STATE,
    PLAYER_STATE,
};

enum ConnectionState {
    DIALOG_DISCONNECTED = 0,
    DIALOG_CONNECTED,
};

enum ConvDialogState {
    DIALOG_IDLE = 0,
    DIALOG_LISTENING,
    DIALOG_RESPONDING,
    DIALOG_THINKING,
};

enum ConvAppAction {
    MIC_STARTED = 0,
    MIC_STOPPED,
    PLAYER_STARTED,
    PLAYER_STOPPED,
    APP_ENTER_BACKGROUND,
    APP_ENTER_FOREGROUND,
    ENABLE_VOICE_INTERRUPT,
    DISABLE_VOICE_INTERRUPT,
    VOICE_MUTE,
    VOICE_UNMUTE,
    START_HUMAN_SPEECH,   /* V0.3.0新增, 仅在push2talk模式有效, 表示用户开始说话 */
    STOP_HUMAN_SPEECH,    /* V0.3.0新增, 仅在push2talk模式有效, 表示用户说话完毕 */
    CANCEL_HUMAN_SPEECH,  /* V0.3.1新增, 仅在push2talk模式有效, 表示用户说话取消 */
    PULL_OUT_HEADPHONES,
    CONTINUE,
    VOICE_DETECTED_BEGIN,
    VOICE_DETECTED_END,
    VOICE_TIMEOUT,
    KEYWORD_TRUSTED,
    ENABLE_MONOLOGUE_MODE,  /* V1.4.0新增 */
    DISABLE_MONOLOGUE_MODE, /* V1.4.0新增 */
};

enum InterruptionPolicy {
    INTERRUPTION_POLICY_NONE = 0,
    INTERRUPTION_POLICY_ACCEPT,
    INTERRUPTION_POLICY_DENY,
    INTERRUPTION_POLICY_ASK,
};

typedef enum ConvEventType ConvEventType;
typedef enum ConvStateType ConvStateType;
typedef enum ConnectionState ConnectionState;
typedef enum ConvDialogState ConvDialogState;
typedef enum ConvAppAction ConvAppAction;


@protocol NativeConversationSdkDelegate <NSObject>
@optional
-(void) onConvEventCallback:(ConvEventType)event_type
                        statusCode:(int)status_code
                        errMsg:(const char*)error_message
                        result:(const char*)response
                        taskId:(const char*)task_id
                      dialogId:(const char*)dialog_id
                     terminate:(BOOL)terminate;
-(void) onConvRequestCallback:(ConvEventType)event_type
                      request:(const char*)request
                       taskId:(const char*)task_id
                     dialogId:(const char*)dialog_id;
-(void) onConvConnectionChangedCallback:(int)state;
-(void) onConvStateChangedCallback:(int)state;
-(int) onConvDataSendCallback:(unsigned char *)data
                       length:(int)len
                   sampleRate:(int)sample_rate
                        level:(int)level
                channelSelect:(int)channel_select;
-(int) onConvDataReceivedCallback:(unsigned char *)data length:(int)len;
-(void) onConvSoundLevelCallback:(int)level
                              db:(float)db;
-(void) onConvNetworkEventCallback:(int)event_type
                           latency:(int)latency
                          response:(const char*)response;
-(void) onConvEventTrackCallback:(int)level log:(const char*)log;
@end

@interface NativeConversation : NSObject

@property (readonly) void* conv_sdk;
@property (nonatomic,weak) id<NativeConversationSdkDelegate> delegate;

+ (instancetype)get_instance;

//Initialize API
-(ConversationResultCode) create_conversation;
//Release API
-(ConversationResultCode) destroy_conversation;

//Connect API
-(ConversationResultCode) connect:(const char *)parameters;
//Disonnect API
-(ConversationResultCode) disconnect;

//Interrupt API
-(ConversationResultCode) interrupt;

-(ConversationResultCode) update_message:(const char *)parameters;

// send_audio_data API
-(ConversationResultCode) send_audio_data:(const unsigned char *)data
                                      Len:(int)length;
// send_ref_data API
-(ConversationResultCode) send_ref_data:(const unsigned char *)data
                                    Len:(int)length;
// send_response_data API
-(ConversationResultCode) send_response_data:(const char *)parameters;

// get_response API
-(ConversationResultCode) get_response:(const char *)parameters;

// set action
-(int) set_action:(ConvAppAction)action;
// get state
-(int) get_state:(ConvStateType)type;
@end

#endif
