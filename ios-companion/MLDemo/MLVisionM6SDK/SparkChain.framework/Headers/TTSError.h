//
//  TTSError.h
//  SparkChain
//
//  Created by pcfang on 22.2.24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTSError : NSObject

@property(nonatomic, copy, readonly) NSString * sid;

@property(nonatomic, assign, readonly) int code;

@property(nonatomic, copy, readonly) NSString * errMsg;

@end

NS_ASSUME_NONNULL_END
