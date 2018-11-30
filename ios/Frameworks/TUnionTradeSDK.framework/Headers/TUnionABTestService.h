//
//  TUnionABTestService.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/2/10.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#ifndef TUnionABTestService_h
#define TUnionABTestService_h

#import "TradeTypeDefine.h"

NS_ASSUME_NONNULL_BEGIN

/* ABTest服务 */
@protocol TUnionABTestService <NSObject>

- (TUnionABTestStatus)isSsoLoginServiceOn;

- (TUnionABTestStatus)isJumpServiceOn;

- (void)enable:(Boolean)enable;

/* 用于检查ABTest服务是否可用, 如果返回为NO，可能的原因为：服务未成功初始化（请检查commonProtocol是否实现），或服务被强制降级 */
- (BOOL)getServiceStatus;

/* 用于判断是否是TBPass的Url，如果返回YES，需要Load上一跳的URL，否则可能会导致跳转到首页的错误 */
- (BOOL)isTBPassUrl:(NSString *)url;

- (NSString *)getCookieStr;


@end

NS_ASSUME_NONNULL_END

#endif /* TUnionABTestService_h */
