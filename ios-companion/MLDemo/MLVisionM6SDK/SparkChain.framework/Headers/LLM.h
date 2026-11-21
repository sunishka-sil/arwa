//
//  LLM.h
//  SparkChain
//
//  Created by pcfang on 12.9.23.
//

#import <Foundation/Foundation.h>
@class LLM;
@class LLMEvent;
@class LLMError;
@class LLMResult;
@class LLMConfig;
@class LLMOutput;
@class LLMTools;
@class Memory;

NS_ASSUME_NONNULL_BEGIN

typedef enum{
    TEXT_GENERATION = 0,
    IMAGE_GENERATION,
    IMAGE_UNDERSTANDING
} ModelType;

@protocol LLMCallback <NSObject>

- (void)llm:(LLM *)llm onResult:(LLMResult * _Nullable)result usrContext:(id _Nullable)usrContext;

- (void)llm:(LLM *)llm onEvent:(LLMEvent * _Nullable)event usrContext:(id _Nullable)usrContext;

- (void)llm:(LLM *)llm onError:(LLMError * _Nullable)error usrContext:(id _Nullable)usrContext;

@end


@interface LLM : NSObject

@property(nonatomic, weak) id<LLMCallback> callback;

@property(nonatomic, strong, readonly) LLMConfig * config;

#pragma mark - init
- (instancetype)init;

- (instancetype)initWithConfig:(LLMConfig * _Nullable)config;

- (instancetype)initWithCallback:(id<LLMCallback> _Nullable)callback;

- (instancetype)initWithConfig:(LLMConfig * _Nullable)config callback:(id<LLMCallback> _Nullable)callback;

- (instancetype)initWithModelType:(ModelType)modelType config:(LLMConfig *)config;

- (instancetype)initWithModelType:(ModelType)modelType config:(LLMConfig * _Nullable)config memory:(Memory * _Nullable)memory;

#pragma mark - 同步接口
/// 同步获取LLM结果
/// - Parameter query: 用户问题
- (LLMOutput *)run:(NSString *)query;

- (LLMOutput *)run:(NSString *)query image:(NSData *)image;

/// 同步获取LLM结果
/// - Parameters:
///   - query: 用户问题
///   - ttl: 超时时间
- (LLMOutput *)run:(NSString *)query ttl:(int)ttl;

/// 同步获取LLM结果
/// - Parameters:
///   - query: 用户问题
///   - tools: 工具（如function call）
- (LLMOutput *)run:(NSString *)query tools:(LLMTools *)tools;

/// 同步获取LLM结果
/// - Parameters:
///   - query: 用户问题
///   - tools: 工具（如function call）
///   - ttl: 超时时间
- (LLMOutput *)run:(NSString *)query tools:(LLMTools *)tools ttl:(int)ttl;

/// 同步获取图片理解结果
/// - Parameters:
///   - query: 用户问题
///   - image: 图片
- (LLMOutput *)run:(NSString *)query image:(NSData *)image;

/// 使用raw json同步调用大模型
/// - Parameters:
///   - json: 原始JSON
///   - ttl: 超时时间
- (LLMOutput *)runWithJSON:(NSString *)json ttl:(int)ttl;

#pragma mark - 异步接口
/// 异步获取LLM结果
/// - Parameter query: 用户问题
- (int)arun:(NSString *)query;

/// 异步获取LLM结果
/// - Parameters:
///   - query: 用户问题
///   - usrContext: 用户自定义数据
- (int)arun:(NSString *)query usrContext:(id _Nullable)usrContext;

- (int)arun:(NSString *)query image:(NSData *)image usrContext:(id _Nullable)usrContext;

/// 异步获取LLM结果
/// - Parameters:
///   - query: 用户问题
///   - tools: 工具（如function call）
- (int)arun:(NSString *)query tools:(LLMTools *)tools;

///  异步获取LLM结果
/// - Parameters:
///   - query: 用户问题
///   - tools:  工具（如function call）
///   - usrContext:  用户自定义数据
- (int)arun:(NSString *)query tools:(LLMTools *)tools usrContext:(id _Nullable)usrContext;

/// 异步获取图片理解结果
/// - Parameters:
///   - query: 用户问题
///   - image: 图片
- (int)arun:(NSString *)query image:(NSData *)image;

/// 异步获取图片理解结果
/// - Parameters:
///   - query: 用户问题
///   - image: 图片
///   - usrContext: 用户自定义数据
- (int)arun:(NSString *)query image:(NSData *)image usrContext:(id _Nullable)usrContext;

/// 使用raw json异步调用大模型
/// - Parameters:
///   - json: 原始JSON
///   - usrContext: 用户自定义数据
- (int)arunWithJSON:(NSString *)json usrContext:(id _Nullable)usrContext;

#pragma mark - 其他
/// 添加system角色（如：你是一个智能旅游助手，推荐旅游地点）
/// - Parameter prompt: system内容
- (int)addSystemPrompt:(NSString *)prompt;

/// 清除上下文
- (void)clearHistory;

/// 停止输出
- (int)stop;

@end


@interface LLMFactory : NSObject

+ (LLM *)textGeneration:(LLMConfig * _Nullable)config;

+ (LLM *)textGeneration:(LLMConfig * _Nullable)config memory:(Memory * _Nullable)memory;

+ (LLM *)imageGeneration:(LLMConfig * _Nullable)config;

+ (LLM *)imageGeneration:(LLMConfig * _Nullable)config width:(int)width height:(int)height;

+ (LLM *)imageUnderstanding:(LLMConfig * _Nullable)config;

+ (LLM *)imageUnderstanding:(LLMConfig * _Nullable)config memory:(Memory * _Nullable)memory;
@end

NS_ASSUME_NONNULL_END
