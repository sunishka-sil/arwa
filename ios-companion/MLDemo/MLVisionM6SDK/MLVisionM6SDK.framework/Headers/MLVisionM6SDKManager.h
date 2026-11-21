//
//  MLAndesManager.h
//  MLAndesSDK
//
//  Created by Lemon on 2025/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//typedef NS_ENUM(NSInteger, MLVisionFunctionType)
//{
//    MLVisionFunctionKeepAidl = -1,
//    MLVisionFunctionKeepAlive = 0,// keep-alive
//    MLVisionFunctionAppManager = 1, // app manager (glasses enter/exit the corresponding app)
//    MLVisionFunctionGlobalUI = 2,
//    MLVisionFunctionBtConnect = 3,
//    MLVisionFunctionOTA = 9,
//    MLVisionFunctionDeviceInfo = 10,// device management
//    MLVisionFunctionNavi = 11,
//    MLVisionFunctionMusic = 12,
//    MLVisionFunctionTranslate = 13,
//    MLVisionFunctionReader = 14,
//    MLVisionFunctionReminder = 15,
//    MLVisionFunctionPrompter = 16,
//    MLVisionFunctionAi = 17,
//    MLVisionFunctionAssistant = 18,// voice assistant
//    MLVisionFunctionHeadAccessory = 19,// hearing assist
//    MLVisionFunctionStation = 20,
//    MLVisionFunctionSetting = 21,
//    MLVisionFunctionWifi = 22, // Wi-Fi P2P module
//    MLVisionFunctionAlbum = 23,
//    MLVisionFunctionLog = 24,
//    MLVisionFunctionCamera = 25,
//    MLVisionFunctionAudio = 26,
//    MLVisionFunctionVideo = 28,
//    MLVisionFunctionRing = 29,
//    MLVisionFunctionGlassFile = 27, // glasses file-transfer module
//    MLVisionFunctionUSER_DEFINE_TASK = 200,
//    MLVisionFunctionUSER_DEFINE_JOB = 201,
//    MLVisionFunctionUSER_DEFINE_MSG = 202,
//    MLVisionFunctionUSER_DEFINE_CHAN = 203,
//    MLVisionFunctionUSER_DEFINE_BIZ = 204,
//    MLVisionFunctionUSER_DEFINE_APP = 205,
//    MLVisionFunctionUSER_DEFINE_CTRL = 206,
//    MLVisionFunctionUSER_DEFINE_INFO = 207,
//    MLVisionFunctionUSER_DEFINE_SUBJ = 208,
//    MLVisionFunctionUSER_DEFINE_SERV = 209
//};

typedef NS_ENUM(NSInteger, MLVisionOTAStatusType)
{
    MLVisionOTAStatusTypeZip = 1, // unzipping the file
    MLVisionOTAStatusTypeFileUpload = 2,
    MLVisionOTAStatusTypeUploadFinish = 3 // after the file is uploaded, the glasses report whether it succeeded
};

typedef NS_ENUM(NSInteger, MLVisionFileTransferType)
{
    MLVisionFileTransferTypeWaitSendFile = 1,
    MLVisionFileTransferTypDownloadFile = 2,
    MLVisionFileTransferTypeDeleteFile = 3,
    MLVisionFileTransferTypeError = 4
};

typedef NS_ENUM(NSUInteger, MLSDKLanguageType) {
    MLSDKLanguageType_SimpleChinese = 0,         // Simplified Chinese
    MLSDKLanguageType_English,               // English
    MLSDKLanguageType_Japanese,              // Japanese
    MLSDKLanguageType_Korean,                // Korean
    MLSDKLanguageType_Spanish,               // Spanish
    MLSDKLanguageType_Portuguese,            // Portuguese
    MLSDKLanguageType_TraditionalChinese,    // Traditional Chinese
    MLSDKLanguageType_French                 // French
};


typedef NS_ENUM(NSInteger, MLVisionWakeupType)
{
    MLVisionWakeupTypeASR = 0,
    MLVisionWakeupTypeNLU = 1,
    MLVisionWakeupTypeASRNLU = 2,
};

typedef NS_ENUM(NSInteger, MLVisionTTSNextAction)
{
    MLVisionTTSNextActionStep = 0,
    MLVisionTTSNextActionExit = 1,
    MLVisionTTSNextActionStepExit = 2

};

typedef NS_ENUM(NSInteger, MLVisionAssistantResultType)
{
    MLVisionAssistantResultTypeASR = 0,
    MLVisionAssistantResultTypeNLU = 1,
    MLVisionAssistantResultTypeSpeakable = 5,
    MLVisionAssistantResultTypeCmd = 6,
    MLVisionAssistantResultTypPpageItemClick = 7,
    MLVisionAssistantResultTypeError = -1,

};


typedef void(^MLBLEMessageBlock)(NSInteger,NSDictionary *);
typedef void(^MLBLEAudioMessageBlock)(NSInteger,NSData *);
typedef void(^MLBLEOtaBlock)(MLVisionOTAStatusType,NSDictionary *);

typedef void(^MLFileTransferBlock)(MLVisionFileTransferType,id);

typedef void(^MLBLEGlassFileUpdateBlock)(NSDictionary *);

typedef void(^MLAssistantResultBlock)(MLVisionAssistantResultType,NSDictionary *);

typedef void(^MLBleWifiChangedBlock)(NSDictionary *);
typedef void(^MLBleWifiConnectResultBlock)(BOOL);

typedef void(^MLSimulInterpretingResultBlock)(NSDictionary*);

typedef void(^MLSimulInterpretingAudioPathBlock)(NSString * textPath,NSString *wavPath);

typedef void(^MLOtaProgressUpdateBlock)(NSInteger,NSInteger);
typedef void(^MLOtaOnSuccessBlock)(NSInteger);
typedef void(^MLOtaOnErrorBlock)(NSInteger,NSString*);

typedef void(^MLTranscribeBlock)(NSString*,NSError*);
typedef void(^MLTranscribeProgressBlock)(NSInteger,NSInteger);

// New block types that support concurrent transcription (include the file identifier)
typedef void(^MLTranscribeBlockWithFile)(NSString* filePath, NSString* content, NSError* _Nullable error, NSInteger startTimeMillis, NSInteger endTimeMillis);
typedef void(^MLTranscribeProgressBlockWithFile)(NSString* filePath, NSInteger current, NSInteger total);
typedef void(^MLAssistantEngineSteteBlock)(NSString* engState,
                                           NSDictionary* extra);
// Recording transcription: recording finished callback
typedef void(^MLAudioRecordCompleteBlock)(NSDictionary* result);

// Recording transcription: live recognized text
typedef void(^MLAudioRecordRecognizingBlock)(NSString* text);

// Recording transcription: summary finished callback
typedef void(^MLAudioRecordSummaryCompleteBlock)(NSDictionary* result);
// New: callback after the summary is saved to a local file (returns the .txt file path)
typedef void(^MLAudioSummaryFileBlock)(NSString* txtFilePath);
// Summary records
typedef void(^MLAudioSummaryRecordsBlock)(NSArray* records);



@protocol MLVisonIflyProtocol <NSObject>

- (void)initIflySDK:(NSString*)sn;
- (void)sendWakeUpMsg:(NSString*)sn;
- (void)sendSleepMsg;
- (void)ttsPlay:(NSString*)tts speed:(NSInteger)speed;
- (void)ttsPause;
- (void)ttsResume;
- (void)ttsStop;
- (void)startRecord;
- (void)stopRecord;
- (void)startSendData:(NSData*)data;
- (void)stopSendData;

- (void)startListning;
- (void)stopListening;
- (void)destroyListening;
- (void)cancelListening;
- (void)initIflyRecognize;

@end


@protocol MLVisionIflyRecognizeSDKProtocol <NSObject>
- (void)iflyrecognizeData:(NSArray*)data isLast:(BOOL)isLast;
@end


@protocol MLVisionIflySDKProtocol <NSObject>

- (void)onEvent:(NSInteger)event;
- (void)onTTSEvent:(NSInteger)event;
- (void)progressResult:(NSString*)result eventData:(NSDictionary*)eventData;

@end


@interface MLVisionM6SDKManager : NSObject

/// Initialize the SDK
+ (void)SDKInitWithDelegate:(NSObject*)delegate;

+ (void)initAliAcount:(NSString*)apiKey appID:(NSString*)appID spaceID:(NSString*)spaceID;


/// BLE: start scanning for devices
+(void)startScan;

/// BLE: stop scanning for devices
+(void)stopScan;

/// BLE: start connecting to the device
+(void)startConnect;

/// Cancel the connection
+(void)cancelConnect;

/// BLE: unpair from the glasses
+(void)unbound;



/// Get the glasses' device info
+(NSDictionary*)getGlassInfo;

/// Enable logging
/// isOpen: true = on, false = off
+(void)setLog:(BOOL)isOpen;


/// Send a message to the glasses; see the corresponding app's protocol for the message format
+(void)sendBLEMessage:(NSInteger)type message:(NSDictionary*)message;


/// Handle data returned by the glasses
/// - Parameter block: callback for messages from the glasses
+(void)handleBLEMessage:(MLBLEMessageBlock)block;


/// Set the glasses' volume
+(void)setGlassVolume:(NSInteger)volume;


/// File operations
/// Phone asks the glasses which files are waiting to be synced to the phone
+(void)requestWaitSendFile;

/// Phone tells the glasses which files to sync
+(void)sendTransferFile:(NSArray*)fileArray;

/// Phone tells the glasses which files it has received
+(void)sendFileArrayDownloadConfirm:(NSArray*)fileArray;

/// Phone tells the glasses it has received a file
+(void)sendFileDownloadConfirm:(NSString*)file;

/// Phone tells the glasses which files to delete
+(void)sendFileArrayDelete:(NSArray*)fileArray;

/// Delete local files
+(void)deleteLocalFile:(NSArray*)fileArray;


/// File-transfer callbacks
+(void)fileTransferBlock:(MLFileTransferBlock)block;



// Voice assistant module
// Voice wake-up
+(void)registDomain:(NSArray*)domainArray;

+(void)startAssistant:(MLVisionWakeupType)type tts:(NSString*)tts modelId:(NSString*)modelId;
// Exit the voice assistant
+(void)stopAssistant;
// Speak text (TTS)
+(void)playTTSForAssistant:(MLVisionTTSNextAction)action text:(NSString*)text modelId:(NSString*)modelId;
// Stop speaking
+(void)stopTTSForAssistant;
// ASR intercept, off by default; each call toggles it (call again after enabling to turn it off)
+(void)switchAsrIntercept;
// TTS returns audio; not yet supported on iOS
+(void)switchWgAssistant;
+(void)onEngineStateBlock:(MLAssistantEngineSteteBlock)block;

// Sync third-party command words
+(void)syncThirdCmd:(NSString*)model cmdArray:(NSArray*)cmdArray;

// Tell the glasses to set the notification flavor
+(void)notifyFlavor:(NSString*)flavor;
// Speech recognition results
+(void)assistantResultBlock:(MLAssistantResultBlock)block;

// Launch the glasses' photo, audio-recording or video app
+(void)openApp:(NSInteger)app ext:(NSDictionary*)ext;

// Exit the glasses' photo, audio-recording or video app
+(void)exitApp:(NSInteger)app ext:(NSDictionary*)ext;

// Simultaneous interpretation
// Start interpreting
+(void)startSimulInterpreting;
// Stop interpreting
+(void)stopSimulInterpreting:(BOOL)isEndAndSave;
// Whether interpreting is in progress
+(BOOL)isSimulInterpreting;
// Get the source language
+(NSString*)getSourceLanguage;
// Get the target language
+(NSString*)getTargetLanguage;
// Set the source language
+(void)setSourceLanguage:(NSString*)language;
// Set the target language
+(void)setTargetLanguage:(NSString*)language;
// Get the supported source languages
+(NSArray*)getSupportedSourceLanguages;
// Get the supported target languages
+(NSArray*)getSupportedTargetLanguages;
// Swap languages
+(void)swapLanguages;
// Mute
+(void)muteTts:(BOOL)mute;
// Live translation result callback
+(void)setSimulInterpretingResultBlock:(MLSimulInterpretingResultBlock)block;
// Callback with the recording files after interpreting ends
+(void)setSimulInterpretingAudioPathBlock:(MLSimulInterpretingAudioPathBlock)block;



// OTA update
+(void)startOtaUpdateFilePath:(NSString*)filePath fileName:(NSString*)fileName fileSize:(NSInteger)fileSize;
+(void)setOtaOnProgressUpdateBlock:(MLOtaProgressUpdateBlock)block;
+(void)setOtaOnSuccessBlock:(MLOtaOnSuccessBlock)block;
+(void)setOtaOnErrorBlock:(MLOtaOnErrorBlock)block;



// Audio transcription (concurrent, with file identifier and error handling)
+(void)startTranscribeWithFilePath:(NSString*)filePath;
+(void)setTranscribeChangedBlockWithFile:(MLTranscribeBlockWithFile)block;
+(void)setTranscribeSuccessBlockWithFile:(MLTranscribeBlockWithFile)block;
+(void)setTranscribeProgressBlockWithFile:(MLTranscribeProgressBlockWithFile)block;


// Recording transcription
+(void)setAudioRecordCompleteBlockWithFile:(MLAudioRecordCompleteBlock)block;
+(void)setAudioRecordSummaryBlockWithFile:(MLAudioRecordSummaryCompleteBlock)block;
+(void)setAudioRecordRecognizingBlock:(MLAudioRecordRecognizingBlock)block;
// New: set the callback for after the summary is saved to a local file
+(void)setAudioSummaryFileBlock:(MLAudioSummaryFileBlock)block;
+(void)startAudioRecording;
+(void)stopAudioRecording;
+(void)cancelAudioRecording;
+(void)loadAudioRecordsBlock:(MLAudioSummaryRecordsBlock)block;
+(BOOL)deleteAudioRecordByUUID:(NSString *)uuid;
+(BOOL)deleteAllAudioRecords;
// The following are SDK hooks for iFlytek AIUI; you can ignore them

+(void)handleIflyRecognizeData:(NSArray*)result isLast:(BOOL)isLast;

+(void)handleIflyData:(NSString*)info eventData:(NSDictionary*)eventData;

+(void)handleIflyEvent:(NSInteger)event;

+(void)handleIflyTTSEvent:(NSInteger)event;

+(void)showErrorLog:(NSString*)message;

@end

NS_ASSUME_NONNULL_END
