//
//  LLMTools.h
//  SparkChain
//
//  Created by pcfang on 2024/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LLMTools : NSObject

@property(nonatomic, copy) NSString * toolType;

@property(nonatomic, copy) NSString * toolDescription;

- (instancetype)initWithType:(NSString *)type description:(NSString *)description;

@end

NS_ASSUME_NONNULL_END
