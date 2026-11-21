//
// Created by Geeker Aven on 2024/4/15.
//
#import <Foundation/Foundation.h>


OBJC_EXPORT
@interface AlivcEnv : NSObject

/**
 * @brief 环境定义
 *  ENV_GLOBAL_DEFAULT 全球环境，基于上海
 *  ENV_CN 中国大陆
 *  ENV_SEA 东南亚
 *  ENV_GLOBAL_OVERSEA 全球环境，基于新加坡
 */
/**
 * Env define
 * ENV_GLOBAL_DEFAULT : Global environment, base on Shanghai
 * ENV_CN : Chinese mainland.
 * ENV_SEA : Southeast Asia
 * ENV_GLOBAL_OVERSEA: Global environment, base on Singapo
 */
typedef NS_ENUM(NSInteger, AlivcGlobalEnv) {
    AlivcGlobalEnv_GLOBAL_DEFAULT = 0,
    AlivcGlobalEnv_CN __attribute__((deprecated)),
    AlivcGlobalEnv_SEA __attribute__((deprecated)),
    AlivcGlobalEnv_GLOBAL_OVERSEA
};

/**
     * @brief 设置特定功能选项
     * @param key 选项key
     * @param value 选项的值
     * @return true:成功 false：失败
     */
- (BOOL) setOption:(NSString *)key value:(NSString *)value;

/**
 * 全球环境
 */
- (BOOL) setGlobalEnvironment:(AlivcGlobalEnv)env;

- (AlivcGlobalEnv) globalEnvironment;

+ (instancetype)getInstance;

@end
