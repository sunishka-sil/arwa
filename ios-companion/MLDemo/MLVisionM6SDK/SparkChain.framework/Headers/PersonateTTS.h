//
//  PersonateTTS.h
//  SparkChain
//
//  Created by pcfang on 23.2.24.
//

#import <Foundation/Foundation.h>
#import "TTS.h"

NS_ASSUME_NONNULL_BEGIN

@interface PersonateTTS : TTS
@property(nonatomic, assign) int topK;

@property(nonatomic, assign) int maxTokens;

@property(nonatomic, copy) NSString * oralLevel;

@property(nonatomic, assign) bool sparkAssist;

- (instancetype)initWithVcn:(NSString *)vcn;
@end

NS_ASSUME_NONNULL_END
