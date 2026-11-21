//
//  AsrCallbacks.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/11.
//

#import <Foundation/Foundation.h>
#import "ASRResult.h"
#import "ASRError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ASRCallbacks <NSObject>

- (void)onResult:(ASRResult *)result usrTag:(id)usrTag;

- (void)onError:(ASRError *)error usrTag:(id)usrTag;

@end


NS_ASSUME_NONNULL_END
