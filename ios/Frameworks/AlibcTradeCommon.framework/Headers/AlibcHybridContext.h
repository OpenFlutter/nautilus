/*
 * AlibcHybridContext.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommon 
 * 版本号：3.1.1.200
 * 发布时间：2017-08-21
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import <UIKit/UIKit.h>

#ifndef AlibcHybridContext_h
#define AlibcHybridContext_h

// 成功返回
#define MSG_RET_SUCCESS     @"BC_SUCCESS"
// JSBridge 功能关闭
#define MSG_RET_CLOSE       @"BC_CLOSED"
// 无此服务
#define MSG_RET_NO_HANDLER  @"BC_NO_HANDLER"
// 权限禁止
#define MSG_RET_NO_PERMIT   @"BC_NO_PERMISSION"
// 失败返回
#define MSG_RET_FAILED      @"BC_FAILED"
// 参数错误
#define MSG_RET_PARAM_ERR   @"BC_PARAM_ERR"
// 发生异常
#define MSG_RET_EXP         @"BC_EXCEPTION"


@interface AlibcHybridContext : NSObject
/** 控制器 */
@property(nonatomic, weak) UIViewController *vc;
/** 网页 */
@property(nonatomic, weak) UIWebView *webView;

- (instancetype)initWithVC:(UIViewController *)vc webView:(UIWebView *)webView requestId:(NSString *)requestId;

//函数执行成功,只能触发一次
- (void)fireSuccess:(NSDictionary *)returnData;

//函数执行失败,只能触发一次
- (void)fireFail:(NSString *)code;

//函数执行失败,只能触发一次
- (void)fireFail:(NSString *)code msg:(NSString *)msg;

//函数执行失败,只能触发一次
- (void)fireFail:(NSString *)code msg:(NSString *)msg data:(NSDictionary *)returnData;

//上报自定义事件,可以多次触发
- (void)fireEvent:(NSString *)eventId data:(NSDictionary *)returnData;

//执行js脚本,同步
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script;

@end

#endif
