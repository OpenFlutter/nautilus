/*
 * AlibcTradeService.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeSDK 
 * 版本号：3.1.1.206
 * 发布时间：2017-09-04
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343 (阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "AlibcTradeResult.h"
#import "AlibcTradePageFactory.h"
#import "AlibcTradeShowParams.h"
#import "AlibcTradeSDKDefines.h"

@class UIViewController;
@class UIWebView;

/** 交易服务 */
@protocol AlibcTradeService <NSObject>

/**
 * 使用百川SDK的webview打开page，可以实现淘宝账号免登以及电商交易支付流程
 *
 * @param parentController            当前view controller. 若isNeedPush为YES, 需传入当前UINavigationController.
 * @param page                        想要打开的page
 * @param showParams                  打开方式的一些自定义参数
 * @param taoKeParams                 淘客参数
 * @param trackParam                  链路跟踪参数
 * @param tradeProcessSuccessCallback 交易流程中成功回调(加购成功(使用+[AlibcTradePageFactory addCartPage:]时)/发生支付)
 * @param tradeProcessFailedCallback  交易流程中退出或者调用发生错误的回调
 *
 * @return 0标识跳转到手淘打开了,1标识用h5打开,-1标识出错
 */
- (NSInteger)          show:(UIViewController *__nonnull)parentController
                       page:(id <AlibcTradePage> __nonnull)page
                 showParams:(nullable AlibcTradeShowParams *)showParams
                taoKeParams:(nullable AlibcTradeTaokeParams *)taoKeParams
                 trackParam:(nullable NSDictionary *)trackParam
tradeProcessSuccessCallback:(nullable void (^)(AlibcTradeResult *__nullable result))onSuccess
 tradeProcessFailedCallback:(nullable void (^)(NSError *__nullable error))onFailure;

/**
 * 使用isv自己的webview打开page，可以实现淘宝账号免登以及电商交易支付流程
 *
 * @param parentController            webView所在的view controller.
 * @param webView                     isv自己的webview,请先设置好自己的delegate先调用本接口,否则拦截登陆等逻辑会失效
 * @param page                        想要打开的page
 * @param showParams                  打开方式的一些自定义参数
 * @param taoKeParams                 淘客参数
 * @param trackParam                  链路跟踪参数
 * @param tradeProcessSuccessCallback 交易流程中成功回调(加购成功(使用+[AlibcTradePageFactory addCartPage:]时)/发生支付)
 * @param tradeProcessFailedCallback  交易流程中退出或者调用发生错误的回调
 *
 * @return  0:  标识跳转到手淘打开了
            1:  标识用h5打开
           -1:  标识出错
 */
- (NSInteger)          show:(UIViewController *__nonnull)parentController
                    webView:(nullable UIWebView *)webView
                       page:(id <AlibcTradePage> __nonnull)page
                 showParams:(nullable AlibcTradeShowParams *)showParams
                taoKeParams:(nullable AlibcTradeTaokeParams *)taoKeParams
                 trackParam:(nullable NSDictionary *)trackParam
tradeProcessSuccessCallback:(nullable void (^)(AlibcTradeResult *__nullable result))onSuccess
 tradeProcessFailedCallback:(nullable void (^)(NSError *__nullable error))onFailure;

@end
