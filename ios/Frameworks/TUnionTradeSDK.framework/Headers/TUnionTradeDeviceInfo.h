//
//  TUnionDeviceInfo.h
//  bunny
//
//  Created by knight on 16/8/5.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUnionTradeDeviceInfo : NSObject

+ (NSString *)mcid;

+ (NSString *)deviceMode;

+ (NSString *)packageName;

+ (NSString *)sdkVersion;

+ (NSString *)appVersion;

+ (NSString *)OS;

+ (NSString *)aliApp;

+ (NSString *)rebuildCid;

+ (NSString *)getCid;

+ (void)setCookie:(NSString *__nonnull)cookieName cookieStr:(NSString *__nonnull)cookieStr;

+ (NSString *)getTUnionUserAgent;

+ (void)appendTUnionUserAgent;

@end

NS_ASSUME_NONNULL_END
