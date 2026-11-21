//
//  ITSError.h
//  SparkChain_Mac
//
//  Created by pcfang on 15.5.24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ITSError : NSObject

@property(nonatomic, copy, readonly) NSString * sid;

@property(nonatomic, assign, readonly) int code;

@property(nonatomic, copy, readonly) NSString * errMsg;

@end

NS_ASSUME_NONNULL_END
