//
//  RTASR.h
//  SparkChain_iOS
//  实时语音转写
//  Created by pcfang on 2024/8/8.
//

#import <Foundation/Foundation.h>
@class RTASRResult;
@class RTASRError;
NS_ASSUME_NONNULL_BEGIN

@protocol RTASRCallback <NSObject>

- (void)onResult:(RTASRResult *) result useInfo:(id _Nullable)userInfo;

- (void)onError:(RTASRError *) error useInfo:(id _Nullable)userInfo;
@end

@interface RTASR : NSObject

//common
@property (nonatomic, copy) NSString * lang;

@property (nonatomic, copy) NSString * punc;

@property (nonatomic, copy) NSString * pd;

@property (nonatomic, assign) int vadMdn;

//国内
@property (nonatomic, copy) NSString * transType;

@property (nonatomic, assign) int transStrategy;

@property (nonatomic, copy) NSString * targetLanguage;

@property (nonatomic, assign) int roleType;

@property (nonatomic, assign) int engLangType;

#pragma region overseas params
@property (nonatomic, copy) NSString * ostContextId;

@property (nonatomic, copy) NSString * ostUid;

@property (nonatomic, copy) NSString * ostDeviceId;

@property (nonatomic, copy) NSString * ostDeviceImei;

@property (nonatomic, copy) NSString * ostDeviceMac;

@property (nonatomic, copy) NSString * ostDeviceImsi;

@property (nonatomic, copy) NSString * ostDeviceOther;

@property (nonatomic, copy) NSString * ostNetType;

@property (nonatomic, copy) NSString * ostNetIsp;

@property (nonatomic, copy) NSString * ostAppVer;

@property (nonatomic, copy) NSString * ostDid;

//business params
@property (nonatomic, copy) NSString * ostFormat;

@property (nonatomic, copy) NSString * ostEncoding;

@property (nonatomic, copy) NSString * ostDomain;

@property (nonatomic, copy) NSString * ostAccent;

@property (nonatomic, copy) NSString * ostRequestId;

@property (nonatomic, copy) NSString * ostDwa;

@property (nonatomic, assign) int ostEos;

@property (nonatomic, copy) NSString * ostRf;

@property (nonatomic, copy) NSString * ostResId;

@property (nonatomic, assign) int ostVto;

@property (nonatomic, assign) int ostNunum;

@property (nonatomic, assign) int ostPptaw;

@property (nonatomic, assign) int ostDyhotws;

@property (nonatomic, assign) int ostSegMax;

@property (nonatomic, assign) int ostSegMin;

@property (nonatomic, assign) float ostSegWeight;

@property (nonatomic, assign) int  ostSpeexSize;

@property (nonatomic, assign) int ostSpkdia;

@property (nonatomic, assign) int ostPgsnum;

@property (nonatomic, assign) int ostLanguageType;

@property (nonatomic, copy) NSString * ostDhw;

@property (nonatomic, assign) int ostDhwMod;

@property (nonatomic, copy) NSArray<NSString *> * ostFeatureList;

@property (nonatomic, assign) int ostRsgid;

@property (nonatomic, assign) int ostRlang;

@property (nonatomic, assign) int ostPgsFlashFreq;

//data param
@property (nonatomic, copy) NSString * ostFrameId;
#pragma endregion overseas params

@property (nonatomic, weak) id<RTASRCallback> delegate;


- (instancetype)initWithSecretKey:(NSString *)secretKey;

- (void)setOstPersonalization:(NSString *)key value:(NSString *)value;

- (int)start;

- (int)startWithUserInfo:(id _Nullable)userInfo;

- (int)write:(NSData *)audioData;

- (int)stop;

@end

NS_ASSUME_NONNULL_END
