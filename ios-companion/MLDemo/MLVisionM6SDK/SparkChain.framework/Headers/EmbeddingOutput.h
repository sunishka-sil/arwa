//
//  EmbeddingOutput.h
//  SparkChain
//
//  Created by pcfang on 2024/11/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EmbeddingData : NSObject

@property (readonly) float * byte NS_RETURNS_INNER_POINTER;

@property (nonatomic, assign) NSUInteger length;

@end

@interface EmbeddingOutput : NSObject

@property (nonatomic,copy,readonly) NSString * sid;

@property (nonatomic,strong,readonly) EmbeddingData * data;

@property (nonatomic,copy,readonly) NSString * raw;

@property (nonatomic,copy,readonly) NSString * errMsg;

@property (nonatomic,assign,readonly) int errCode;

@end

NS_ASSUME_NONNULL_END
