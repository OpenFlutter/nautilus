/*
 * AlibcURLBusContext.h 
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
#import <UIKit/UIKit.h>

@interface AlibcURLBusContext : NSObject
@property(nonatomic, weak) UIWebView *webview;
@property(nonatomic, assign) BOOL bFiltered; //标记本次加载是通过filter触发的
@property(nonatomic, weak) UIViewController *sourceViewController;

@property(nonatomic, strong) NSMutableDictionary *extraData; //附加数据,各个业务可以自己塞,注意key冲突
@property(nonatomic, strong) id tradeData; //电商业务专用附加数据


- (void)setWebviewAndViewController:(UIWebView *)webview controller:(UIViewController *)vc;

//webview触发load事件
- (void)setLoadWithRequest:(NSURLRequest *)request;

//绑定webview点击事件
- (void)bindGesture;




/****   辅助函数,方便后续修改UIWebView到UIWebViewProxy的情况.   ***/
//放在这里是因为bus上的拦截到处都可以用..其实都是工具函数,为了复用
- (void)loadRequest:(NSURLRequest *)request;

- (void)reload;  //刷新webview
- (void)goBack;  //浏览器回退或者无堆栈时pop vc,
- (void)popView;

- (void)smartGoBack;// 根据跳转类型决定是否goback,主要用在取消登陆的场景
@end
