//
//  ASRResult.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/11.
//

#ifndef ASRResult_h
#define ASRResult_h

#import <Foundation/Foundation.h>
#import "Transcription.h"
#import "Vad.h"

NS_ASSUME_NONNULL_BEGIN

@interface ASRResult : NSObject

@property (nonatomic, strong) NSArray<Transcription *> *transcriptions;
@property (nonatomic, strong) NSArray<Vad *> *vads;
@property (nonatomic) int begin;
@property (nonatomic) int end;
@property (nonatomic, copy) NSString *sid;
@property (nonatomic, copy) NSString *bestMatchText;
@property (nonatomic) int status;

@end

NS_ASSUME_NONNULL_END

#endif /* ASRResult_h */
