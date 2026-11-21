//
//  TTS.h
//  SparkChain
//
//  Created by pcfang on 22.2.24.
//

#import <Foundation/Foundation.h>
@class TTS;
@class TTSResult;
@class TTSError;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    Begin,
    Continue,
    End,
} Status;

@protocol TTSCallbacks <NSObject>

- (void)tts:(TTS *)tts onResult:(TTSResult *)result usrContext:(id)usrContext;

- (void)tts:(TTS *)tts onError:(TTSError *)error usrContext:(id)usrContext;
@end

@interface TTS : NSObject

@property(nonatomic, weak) id<TTSCallbacks> cbs;

@property(nonatomic, copy) NSString * vcn;

@property(nonatomic, assign) int speed;

@property(nonatomic, assign) int pitch;

@property(nonatomic, assign) int volume;

@property(nonatomic, assign) int reg;

@property(nonatomic, assign) int rdn;

@property(nonatomic, assign) int sampleRate;

@property(nonatomic, copy) NSString * encoding;

@property(nonatomic, assign) int bitDepth;

@property(nonatomic, assign) int channels;

@property(nonatomic, assign) int frameSize;

@property(nonatomic, assign) int bgs;

@property(nonatomic, assign) BOOL rhy;

@property(nonatomic, assign) int scn;

@property(nonatomic, assign) BOOL version;

@property(nonatomic, assign) int l5SilLen;

@property(nonatomic, assign) int paragraphSilLen;

- (instancetype)init;

- (instancetype)initWithVcn:(NSString *)vcn;

- (int)arun:(NSString *)text;

- (int)arun:(NSString *)text userInfo:(id)userInfo;

- (int)arun:(NSString *)text status:(Status)status;

- (int)arun:(NSString *)text status:(Status)status userInfo:(id)userInfo;

- (void)stop;
@end

NS_ASSUME_NONNULL_END
