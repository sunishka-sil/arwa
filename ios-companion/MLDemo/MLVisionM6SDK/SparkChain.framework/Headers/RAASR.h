//
//  RAASR.h
//  SparkChain_iOS
//
//  Created by pcfang on 2024/8/8.
//

#import <Foundation/Foundation.h>
@class RAASRResult;
@class RAASRError;

NS_ASSUME_NONNULL_BEGIN

@protocol RAASRCallback <NSObject>

- (void)onResult:(RAASRResult *)result userInfo:(id _Nullable)userInfo;

- (void)onError:(RAASRError *)error userInfo:(id _Nullable)userInfo;

@end

@interface RAASR : NSObject

//common
@property (nonatomic, copy) NSString * pd;

@property (nonatomic, copy) NSString * audioURL;

@property (nonatomic, assign) int languageType;

@property (nonatomic, assign) int engSegMax;

@property (nonatomic, assign) int engSegMin;

@property (nonatomic, assign) float engSegWeight;

@property (nonatomic, assign) bool engSmoothproc;

@property (nonatomic, assign) bool engColloqproc;

@property (nonatomic, assign) int engVadMdn;

@property (nonatomic, assign) int engVadMargin;

@property (nonatomic, assign) int engRlang;

//国内
@property (nonatomic, copy) NSString * language;

@property (nonatomic, copy) NSString * resultType;

@property (nonatomic, copy) NSString * hotWord;

@property (nonatomic, assign) int candidate;

@property (nonatomic, assign) int roleType;

@property (nonatomic, assign) int roleNum;

@property (nonatomic, copy) NSString * audioMode;

@property (nonatomic, assign) int standardWav;

@property (nonatomic, assign) int trackMode;

@property (nonatomic, copy) NSString * transLanguage;

@property (nonatomic, assign) int transMode;

//海外
// common params
@property (nonatomic, copy) NSString * ostUid;
@property (nonatomic, copy) NSString * ostDeviceId;
//@property (nonatomic, copy) NSString * ostRequestId;
@property (nonatomic, copy) NSString * ostDeviceImei;
@property (nonatomic, copy) NSString * ostDeviceImsi;
@property (nonatomic, copy) NSString * ostDeviceMac;
@property (nonatomic, copy) NSString * ostDeviceOther;
@property (nonatomic, copy) NSString * ostNetType;
@property (nonatomic, copy) NSString * ostNetIsp;
@property (nonatomic, copy) NSString * ostAppVer;

// business params
@property (nonatomic, copy) NSString * ostTaskType;
@property (nonatomic, copy) NSString * ostFormat;
@property (nonatomic, copy) NSString * ostEncoding;
@property (nonatomic, assign) int ostAudioSize;
@property (nonatomic, copy) NSString * ostAudioSrc;
@property (nonatomic, copy) NSString * ostCallbackKey;
@property (nonatomic, copy) NSString * ostCallbackSecret;
@property (nonatomic, copy) NSArray<NSString *> * ostFeatureList;
@property (nonatomic, assign) int ostProcinfoOn;
@property (nonatomic, assign) int ostVsppOn;
@property (nonatomic, assign) int ostSpeakerNum;
@property (nonatomic, assign) int ostOutputType;
@property (nonatomic, assign) int ostPostprocOn;
@property (nonatomic, assign) int ostResegment;
@property (nonatomic, copy) NSString * ostResId;
@property (nonatomic, assign) int ostDuration;
@property (nonatomic, copy) NSString * ostResUrl;
@property (nonatomic, assign) int ostEnableSubtitle;
@property (nonatomic, assign) int ostVto;
@property (nonatomic, copy) NSString * ostDhw;
@property (nonatomic, assign) int ostNbest;
@property (nonatomic, assign) int ostCombineMax;
@property (nonatomic, assign) int ostNunum;


@property (nonatomic, weak) id<RAASRCallback> delegate;

- (instancetype)initWithSecretKey:(NSString *)apiKey;

- (void)setOstPersonalizationKey:(NSString *)key value:(NSString *)value;

- (int)uploadAsync:(NSString *)fileName requestId:(NSString *)requestId userInfo:(id _Nullable)userInfo;

- (int)uploadAsync:(NSString *)fileName;

- (int)queryResult:(NSString *)orderId userInfo:(id _Nullable)userInfo;

- (int)queryResult:(NSString *)orderId;

//仅国内
- (int)stop;

//海外
- (int)ostRetryTaskWithOrderId:( NSString * _Nonnull )orderId userInfo:(id _Nullable)userInfo;

- (int)ostCancelTaskWithOrderId:( NSString * _Nonnull )orderId requestId:( NSString * _Nonnull )requestId userInfo:(id _Nullable)userInfo;

- (int)ostDeleteTaskWithOrderId:( NSString * _Nonnull )orderId requestId:( NSString * _Nonnull )requestId userInfo:(id _Nullable)userInfo;
@end

NS_ASSUME_NONNULL_END
