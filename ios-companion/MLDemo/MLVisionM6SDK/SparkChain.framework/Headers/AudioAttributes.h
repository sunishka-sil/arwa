//
//  AudioAttributes.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/11.
//

#ifndef AudioAttributes_h
#define AudioAttributes_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AudioAttributes : NSObject

@property (nonatomic, assign) int sampleRate;
@property (nonatomic, copy) NSString *encoding;
@property (nonatomic, assign) int channels;
@property (nonatomic, assign) int bitdepth;
@property (nonatomic, assign) int frameSize;

- (instancetype)init;

@end

NS_ASSUME_NONNULL_END

#endif /* AudioAttributes_h */
