//
//  ITS.h
//  SparkChain_Mac
//
//  Created by pcfang on 15.5.24.
//

#import <Foundation/Foundation.h>
@class ITS;
@class ITSResult;
@class ITSError;
NS_ASSUME_NONNULL_BEGIN

typedef enum {
    ITRANS = 0,   //讯飞翻译
    NIUTRANS     //小牛翻译
} TransType;

@protocol ITSCallbacks <NSObject>

- (void)its:(ITS *)its onResult:(ITSResult *)result userInfo:(id)userInfo;

- (void)its:(ITS *)its onError:(ITSError *)error userInfo:(id)userInfo;

@end

@interface ITS : NSObject

- (instancetype) init;

- (instancetype) initWithType:(TransType)type;

- (instancetype) initWithFormLanguage:(NSString *)from toLanguage:(NSString *)to;

- (instancetype)initWithFormLanguage:(NSString *)from toLanguage:(NSString *)to type:(TransType)type;

@property (nonatomic, weak) id<ITSCallbacks> callbacks;

@property (nonatomic, copy) NSString * fromLanguage;

@property (nonatomic, copy) NSString * toLanguage;

@property (nonatomic, copy) NSString * resId;

- (int)arun:(NSString *)text;

- (int)arun:(NSString *)text userInfo:(id)userInfo;

@end

NS_ASSUME_NONNULL_END
