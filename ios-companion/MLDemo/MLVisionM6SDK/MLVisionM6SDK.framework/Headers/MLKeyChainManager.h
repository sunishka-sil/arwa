//
//  MLKeyChainManager.h
//  xr_ios
//
//  Created by lijuan on 12/19/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MLKeyChainManager : NSObject
+ (NSMutableDictionary *)getKeychainQuery:(NSString *)service ;
 
+ (void)save:(NSString *)service data:(id)data;
 
+ (NSData*)load:(NSString *)service;
 
+ (void)delete:(NSString *)service;
@end

NS_ASSUME_NONNULL_END

