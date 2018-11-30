/*
 * AlibcWebViewService.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommon 
 * 版本号：3.1.1.200
 * 发布时间：2017-08-21
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>

#ifndef AlibcWebViewService_h
#define AlibcWebViewService_h

@class NSURLRequest;
@class UIWebView;
@class UIViewController;

@protocol AlibcWebViewService <NSObject>

- (BOOL)isAllowLoadURLRequest:(NSURLRequest *)request
                      webview:(UIWebView *)webview
         sourceViewController:(UIViewController *)controller;
@end

#endif
