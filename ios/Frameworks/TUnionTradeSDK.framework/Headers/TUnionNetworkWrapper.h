//
//  TUnionNetworkWrapper.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/2/23.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TUnionNetworkProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUnionNetworkWrapper : NSObject

+ (void)sendAsyncConfigRequest:(NSDictionary * _Nullable) param
                       success:(requestSuccess) success
                        failed:(requestFailed) failed;

+ (void)sendAsyncConvertRequest:(NSDictionary * _Nullable) param
                        success:(requestSuccess) success
                         failed:(requestFailed) failed;

+ (void)sendAsyncTokenRequest:(NSDictionary * _Nullable)param
                      success:(requestSuccess) success
                       failed:(requestFailed) failed;

@end

NS_ASSUME_NONNULL_END
