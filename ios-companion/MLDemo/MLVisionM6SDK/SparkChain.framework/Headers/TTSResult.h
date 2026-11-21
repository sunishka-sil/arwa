//
//  TTSResult.h
//  SparkChain
//
//  Created by pcfang on 22.2.24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTSResult : NSObject

@property(nonatomic, copy, readonly) NSString * sid;

@property(nonatomic, assign, readonly) int seq;

@property(nonatomic, copy, readonly) NSData * data;

@property(nonatomic, copy, readonly) NSString * ced;

@property(nonatomic, copy, readonly) NSString * pybuf;

@property(nonatomic, copy, readonly) NSString * version;

@property(nonatomic, assign, readonly) int status;

@end

NS_ASSUME_NONNULL_END
