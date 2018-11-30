/*
 * AlibcUserAgent.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeBiz 
 * 发布时间：3.1.1.204
 * 发布时间：2017-09-04
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>

#ifndef AlibcUserAgent_h
#define AlibcUserAgent_h

FOUNDATION_EXPORT NSString *AlibcUserAgentContextKeyWebView;

@interface AlibcUserAgent : NSObject
/** 装载
 * !!!: 需要主线程调用
 * */
+ (void)install:(NSDictionary *)context;

/** 卸载 */
+ (void)uninstall:(NSDictionary *)context;

@end

#endif
