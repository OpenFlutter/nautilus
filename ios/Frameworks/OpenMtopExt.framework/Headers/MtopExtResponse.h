//
//  MtopExtResponse.h
//  mtopext
//
//  Created by 亿刀/禚来强 on 16/6/15.
//  Copyright © 2016年 亿刀/禚来强. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MtopExtRequest;
@class MtopError;

@interface MtopExtResponse : NSObject

/* http 状态码 */
@property(assign, nonatomic, readonly) int                                      httpStartusCode;

/* 错误信息 */
@property(strong, nonatomic, readonly) MtopError                                *error;

/* http响应头 */
@property(strong, nonatomic, readonly) NSDictionary                             *responseHeaders;

/* 二进制响应 */
@property(strong, nonatomic, readonly) NSData                                   *responseData;

/* 原始的http响应body */
@property(strong, nonatomic, readonly) NSString                                 *responseString;

/* json响应，从http body 解析 */
@property(strong, nonatomic, readonly) NSDictionary                             *responseJsons;

/* 响应对应的API Request */
@property(strong, nonatomic, readonly) MtopExtRequest                           *request;

/* 底层发出去的URL */
@property(strong, nonatomic, readonly) NSURL                                    *requestURL;

@property(assign, nonatomic) BOOL                                               isLoginCancel;

@property(assign, nonatomic) BOOL                                               isAuthCancel;

@end
