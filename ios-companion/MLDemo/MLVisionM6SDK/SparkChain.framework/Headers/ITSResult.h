//
//  ITSResult.h
//  SparkChain_Mac
//
//  Created by pcfang on 15.5.24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Trans : NSObject

@property (nonatomic, copy, readonly) NSString * src;

@property (nonatomic, copy, readonly) NSString * dst;

@end

@interface ITSResult : NSObject

@property (nonatomic, copy, readonly) NSString * sid;

@property (nonatomic, assign, readonly) int status;

@property (nonatomic, copy, readonly) NSString * from;

@property (nonatomic, copy, readonly) NSString * to;

@property (nonatomic, strong, readonly) Trans * trans;

@end

NS_ASSUME_NONNULL_END
