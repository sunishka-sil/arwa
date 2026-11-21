//
//  Memory.h
//  SparkChain
//
//  Created by pcfang on 2024/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Memory : NSObject

- (instancetype) init NS_UNAVAILABLE;

/// 按照轮数进行大模型交互上下文记忆，默认5轮,超出轮数自动移除最早的会话
+ (instancetype)windowMemory;
/// 按照轮数进行大模型交互上下文记忆，用户自定义轮数，超出轮数自动移除最早的会话
+ (instancetype)windowMemory:(int)maxCache;

/// 按照token进行大模型交互上下文记忆，默认4096
+ (instancetype)tokenMemory;
/// 按照token进行大模型交互上下文记忆，用户自定义token
+ (instancetype)tokenMemory:(int)maxToken;

@end

NS_ASSUME_NONNULL_END
