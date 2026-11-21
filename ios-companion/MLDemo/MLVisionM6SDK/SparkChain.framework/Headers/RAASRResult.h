//
//  RAASRResult.h
//  SparkChain_iOS
//
//  Created by pcfang on 2024/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface RAASRTransResult : NSObject

@property (nonatomic, copy, readonly) NSString * segId;

@property (nonatomic, copy, readonly) NSString * dst;

@property (nonatomic, assign, readonly) int bg;

@property (nonatomic, assign, readonly) int ed;

@property (nonatomic, copy, readonly) NSArray <NSString *> * tags;

@property (nonatomic, copy, readonly) NSArray <NSString *> * roles;

@end

@interface RAASRResult : NSObject

//common
@property (nonatomic, assign, readonly) int code;
@property (nonatomic, copy, readonly) NSString * orderResult;

//国内
@property (nonatomic, assign, readonly) int status;
@property (nonatomic, copy, readonly) NSString * orderId;

@property (nonatomic, assign, readonly) long originalDuration;

@property (nonatomic, assign, readonly) long realDuration;

@property (nonatomic, assign, readonly) long expireTime;

@property (nonatomic, assign, readonly) int taskEstimateTime;

@property (nonatomic, copy, readonly) NSArray <RAASRTransResult *> * transResult;

//海外
@property (nonatomic, copy, readonly) NSString * ostTaskStatus;

@property (nonatomic, copy, readonly) NSString * ostSid;

@property (nonatomic, copy, readonly) NSString * ostTaskId;

@property (nonatomic, copy, readonly) NSString * ostTaskType;
@end

NS_ASSUME_NONNULL_END
