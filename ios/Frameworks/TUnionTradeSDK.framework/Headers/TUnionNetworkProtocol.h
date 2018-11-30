//
//  TUnionNetworkProtocol.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/1/10.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#import "TUnionMtopRequest.h"

#ifndef TUnionNetworkProtocol_h
#define TUnionNetworkProtocol_h

/**
 * 网络请求枚举，当前只支持GET和POST
 */

typedef NS_ENUM(NSUInteger, TURequestType) {
    ETUPostType = 0,
    ETUGetType = 1
};

NS_ASSUME_NONNULL_BEGIN

/**
 * 网络请求成功的回调
 * @param response  网络请求成功之后的数据
 */
typedef void(^requestSuccess)( NSData *response);

/**
 * 网络请求失败的回调
 * @param error     网络请求失败之后保存的错误数据
 */
typedef void(^requestFailed)(NSError * error);

@protocol TUnionNetworkProtocol <NSObject>

- (void)sendAsyncRequestWithURL:(NSString *) url
                          param:(NSDictionary * _Nullable) param
                      userAgent:(NSArray<NSString *> * _Nullable) userAgent
                    requestType:(TURequestType) type
                        success:(requestSuccess) success
                         failed:(requestFailed) failed;

@optional
- (void)sendAsyncRequestWithMTop:(TUnionMtopRequest *) request
                          param:(NSDictionary * _Nullable) param
                    requestType:(TURequestType) type
                        success:(requestSuccess) success
                         failed:(requestFailed) failed;

@end

id<TUnionNetworkProtocol> getNetworkInstance();

NS_ASSUME_NONNULL_END

#endif /* TUnionNetworkProtocol_h */
