//
//  ASR.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/10.
//

#ifndef ASR_h
#define ASR_h


#import <Foundation/Foundation.h>
#import "AudioAttributes.h"
#import "ASRCallbacks.h"

NS_ASSUME_NONNULL_BEGIN

@interface ASR : NSObject

@property (nonatomic, weak) id<ASRCallbacks> cbs;

- (instancetype)init;
- (instancetype)initWithLanguage:(NSString *)language domain:(NSString *)domain accent:(NSString *)accent;

- (int)start:(AudioAttributes *)attributes;
- (int)start:(AudioAttributes *)attributes usrTag:(id)usrTag;
- (int)write:(NSData *)data;
- (int)stop:(BOOL)immediate;

- (void)language:(NSString *)language;
- (void)domain:(NSString *)domain;
- (void)accent:(NSString *)accent;
- (void)vadEos:(int)vadEos;
- (void)dwa:(NSString *)dwa;
- (void)pd:(NSString *)pd;
- (void)ptt:(BOOL)enable;
- (void)rlang:(NSString *)rlang;
- (void)vinfo:(BOOL)vinfo;
- (void)nunum:(BOOL)enable;
- (void)speexSize:(int)speexSize;
- (void)nbest:(int)nbest;
- (void)wbest:(int)wbest;
- (void)vgap:(int)vgap;
- (void)proc:(BOOL)proc;
- (void)smth:(BOOL)smth;
- (void)ln:(NSString *)ln;
- (void)opt:(int)opt;
- (void)dhw:(NSString *)dhw;
- (void)ltc:(int)ltc;

@end

NS_ASSUME_NONNULL_END


#endif /* ASR_h */
