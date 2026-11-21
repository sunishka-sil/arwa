//
//  Embedding.h
//  SparkChain
//
//  Created by pcfang on 2024/11/28.
//

#import <Foundation/Foundation.h>
@class EmbeddingOutput;
NS_ASSUME_NONNULL_BEGIN

@interface Embedding : NSObject

+ (EmbeddingOutput *)embedding:(NSString *)input domain:(NSString *)domain;

+ (EmbeddingOutput *)embedding:(NSString *)input domain:(NSString *)domain uid:(NSString * __nullable)uid;

@end

NS_ASSUME_NONNULL_END
