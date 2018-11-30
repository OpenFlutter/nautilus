//
//  TBSDKConfiguration.h
//  mtopext
//
//  Created by 亿刀/禚来强 on 16/6/15.
//  Copyright © 2016年 亿刀/禚来强. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TBSDKAccountInfo;

typedef enum {
    
    /**< 枚举，预发环境 */
    TBSDKEnvironmentDebug =  1,
    
    /**< 枚举，日常环境 */
    TBSDKEnvironmentDaily,
    
    /**< 枚举，正式环境 */
    TBSDKEnvironmentRelease
    
} TBSDKEnvironment;

@interface TBSDKConfiguration : NSObject

/* 设置环境 */
@property (nonatomic, unsafe_unretained) TBSDKEnvironment                       environment;

/* 无线埋点的 ttid */
@property (nonatomic, strong) NSString                                          *wapTTID;

/* 自定义域名 */
@property (nonatomic, strong) NSString                                          *customHost;

/* 加签码 */
@property (nonatomic, strong) NSString                                          *authCode;

/* 应用程序的 appKey */
@property (nonatomic, strong, readonly) NSString                                *appKey;

/* 设备标示 */
@property(strong, nonatomic, readonly) NSString                                 *utdid;

/* 服务器时间 */
@property(strong, nonatomic, readonly) NSDate                                   *serverDate;


/* 获取单例对象 */
+ (id)shareInstance;

@end