//
//  RTASRResult.h
//  SparkChain_iOS
//
//  Created by pcfang on 2024/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTASRTransResult : NSObject

@property(nonatomic, assign, readonly) int status;

@property(nonatomic, copy, readonly) NSString * src;

@property(nonatomic, copy, readonly) NSString * dst;

@end

@interface RTASRResult : NSObject

@property(nonatomic, assign, readonly) int status;

@property(nonatomic, copy, readonly) NSString * sid;

@property(nonatomic, copy, readonly) NSString * data;

@property(nonatomic, copy, readonly) NSString * raw;

@property(nonatomic, copy, readonly) RTASRTransResult * transResult;

@property(nonatomic, copy, readonly) NSString * ostContextId;

@end

NS_ASSUME_NONNULL_END
