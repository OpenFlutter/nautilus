//
//  TUnionMacros.h
//  TUnionSDK
//
//  Created by HuXiaoNing on 2016/12/9.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifndef TUnionMacros_h
#define TUnionMacros_h

//---------MARK: TUnionTrade debug log

#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x

#ifdef DEBUG // 仅在debug模式下有效
#define TUnionTradeLog(format, ...) NSLog(@"TUnionTradeLib::[%s:%d]" format, filename(__FILE__), __LINE__, ##__VA_ARGS__);
#else
#define TUnionTradeLog(format, ...) 
#endif
 
#define getError(errorCode) [TError getError:errorCode]


//---------MARK: ErrorCode define

typedef NS_ENUM (NSUInteger, TUnionTradeErrorCode) {
    TUnionTrade_INIT_FAILED = 1000,
    TUnionTrade_Invalied_Webview = 111,
    TUnionTrade_Network_Error = 122,
    TUnionTrade_Common_Protocol_Failure = 1002002,
    TUnionTrade_ERROR_CODE_END      /*must be end*/
};

typedef struct _TUnionTrdeError {
    TUnionTradeErrorCode code;
    char *message;
} TUnionTrdeError;

static const TUnionTrdeError TUnionTrdeErrorList[] = {
    { TUnionTrade_INIT_FAILED, "TUnionTradeSDK 初始化失败"},
    { TUnionTrade_Invalied_Webview, "无效WebView"},
    { TUnionTrade_Common_Protocol_Failure, "TUnionCommonProtocol协议未实现"},
    { TUnionTrade_ERROR_CODE_END, ""}    /* must be end*/
};

static NSString * TUnionTrade_SDK_ERROR_DOMAIN = @"com.tunionsdk";

//---------MARK: Const string information

static NSString * TUNIONTRADE_SDK_VERSION = @"1.3.1";

static NSString * TUNIONTRADE_COOKIE_CID = @"cid";

static NSString * TUNIONTRADE_COOKIE_NAME = @"sdk_param";

static NSString * TUNIONTRADE_HOST_CONFIG_SERVER = @"https://tunion-api.m.taobao.com/config";
static NSString * TUNIONTRADE_HOST_CONFIG_MTOP = @"mtop.taobao.tbk.sdk.config";
static NSString * TUNIONTRADE_HOST_CONFIG_SERVER_PRE = @"http://api.union.m.proxy.taobao.org/config";   //预发环境

//转链接服务接口
static NSString * TUNIONTRADE_HOST_SCLICK_SERVER = @"https://tunion-api.m.taobao.com/convert";

static NSString * TUNIONTRADE_HOST_SCLICK_MTOP = @"mtop.taobao.tbk.sdk.item.convert";

static NSString * TUNIONTRADE_HOST_TOKEN_SERVER = @"https://tunion-api.m.taobao.com/token";
#endif /* TUnionMacros_h */
