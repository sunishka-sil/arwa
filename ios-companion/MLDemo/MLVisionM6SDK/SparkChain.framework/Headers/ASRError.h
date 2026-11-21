//
//  ASRError.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/11.
//

#ifndef ASRError_h
#define ASRError_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASRError : NSObject

@property (nonatomic, assign) int code;
@property (nonatomic, copy) NSString *errMsg;
@property (nonatomic, copy) NSString *sid;

@end

NS_ASSUME_NONNULL_END

#endif /* ASRError_h */
