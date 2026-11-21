//
// Created by Pi on 2023/06/07.
//

#import <Foundation/Foundation.h>
#include "AlivcEnv.h"
/**
 * 一体化基础接口
 */
OBJC_EXPORT
@interface AlivcBase : NSObject

/**
 * SDK版本号
 */
@property (nonatomic, class, readonly) NSString *SDKVersion;

/**
 * SDK构建ID
 */
@property (nonatomic, class, readonly) NSString *SDKBuildId;

/**
 * SDK构建时间
 */
@property (nonatomic, class, readonly) NSString *SDKBuildTime;

/**
 * 集成方式
 */
@property (nonatomic, class) NSString *IntegrationWay;


/**
 * SDK环境控制
 */
@property (nonatomic, class, readonly) AlivcEnv *EnvironmentManager;

@end
