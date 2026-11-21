//
//  RTASRError.h
//  SparkChain_iOS
//
//  Created by pcfang on 2024/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTASRError : NSObject

@property (nonatomic, assign) int code;

@property (nonatomic, copy) NSString *errMsg;

@property (nonatomic, copy) NSString *sid;

//海外
@property (nonatomic, copy) NSString *ostContextId;

@end

NS_ASSUME_NONNULL_END
