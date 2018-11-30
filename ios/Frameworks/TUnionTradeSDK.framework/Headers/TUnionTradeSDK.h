//
//  TUnionTradeSDK.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/1/10.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TUnionWebViewProtocol.h"
#import "TUnionUtProtocol.h"
#import "TUnionNetworkProtocol.h"
#import "TUnionABTestService.h"
#import "TUnionCommonProtocol.h"


@interface TUnionTradeSDK : NSObject

+ (instancetype) shareInstance;

/* 获取转链服务实例 */
- (id)getConvertService;

/* 获取ABTest配置实例 */
- (id<TUnionABTestService>)getABTestService;

/* 获取TUnionSdk的UA */
+ (NSString *)getTUnionUserAgent;

+ (NSString*)sdkVersion;

@end
