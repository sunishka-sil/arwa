//
//  OnlineTTS.h
//  SparkChain_Mac
//
//  Created by XX on 2024/5/10.
//

#import <Foundation/Foundation.h>
#import "TTS.h"

NS_ASSUME_NONNULL_BEGIN

@interface OnlineTTS : TTS

@property (nonatomic, copy) NSString *aue;
@property (nonatomic, assign) int sfl;
@property (nonatomic, copy) NSString *auf;
@property (nonatomic, copy) NSString *tte;

- (instancetype)initWithVcn:(NSString *)vcn;

@end

NS_ASSUME_NONNULL_END
