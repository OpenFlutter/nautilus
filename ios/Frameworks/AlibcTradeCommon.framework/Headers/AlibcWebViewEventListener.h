/*
 * AlibcWebViewEventListener.h 
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
#import <Foundation/Foundation.h>

#import "AlibcMultiDelegates.h"

#ifndef AlibcWebViewEventListener_h
#define AlibcWebViewEventListener_h

/**
 AlibcWebViewEventListener 协议, 添加到 AlibcWebViewEventListenerCenter 的实例需要服从这个协议
 */
@protocol AlibcWebViewEventListener <NSObject>

@optional

/**
 前面的参数同 - (void)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
 @param returnValue Delegate 响应时的返回值
 */
- (void)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType returnValue:(BOOL)returnValue;

/**
 WebView 开始加载
 */
- (void)webViewDidStartLoad:(UIWebView *)webView;

/**
 WebView 结束加载
 */
- (void)webViewDidFinishLoad:(UIWebView *)webView;

/**
 WebView 加载失败

 @param error error instance
 */
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end


/**
 WebView 回调事件的监听中心
 */
@interface AlibcWebViewEventListenerCenter : AlibcMultiDelegates <AlibcWebViewEventListener>


/**
 监听中心的默认实现
 */
@property(class, readonly, strong) AlibcWebViewEventListenerCenter *defaultCenter;

@end

#endif
