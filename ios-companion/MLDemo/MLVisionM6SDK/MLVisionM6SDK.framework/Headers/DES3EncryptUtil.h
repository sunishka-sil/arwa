//
//  DES3EncryptUtil.h
//  xr_ios
//
//  Created by lijuan on 12/19/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DES3EncryptUtil : NSObject
//// 加密方法
+ (NSString*)encrypt:(NSString*)plainText;
// 
//// 解密方法
//+ (NSString*)decrypt:(NSString*)encryptText;
//
//
//+ (NSData *)generateRandomData:(NSUInteger)byteCount;
@end

NS_ASSUME_NONNULL_END
