//
//  RAASRError.h
//  SparkChain_iOS
//
//  Created by pcfang on 2024/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RAASRError : NSObject
//common
@property (nonatomic, assign) int code;

@property (nonatomic, copy) NSString *errMsg;

//国内
@property (nonatomic, copy) NSString *orderId;

@property (nonatomic, assign) int failType;

//海外
//海外
@property (nonatomic, copy, readonly) NSString * ostTaskStatus;

@property (nonatomic, copy, readonly) NSString * ostSid;

@property (nonatomic, copy, readonly) NSString * ostTaskId;

@property (nonatomic, copy, readonly) NSString * ostTaskType;

@end

NS_ASSUME_NONNULL_END
