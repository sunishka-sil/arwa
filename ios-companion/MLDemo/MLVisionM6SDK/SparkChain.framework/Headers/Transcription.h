//
//  Transcription.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/11.
//

#ifndef Transcription_h
#define Transcription_h

#import <Foundation/Foundation.h>
#import "Segment.h"

NS_ASSUME_NONNULL_BEGIN

@interface Transcription : NSObject

@property (nonatomic) int index;
@property (nonatomic, strong) NSArray<Segment *> *segments;

@end

NS_ASSUME_NONNULL_END

#endif /* Transcription_h */
