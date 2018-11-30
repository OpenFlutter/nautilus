/*
 * AlibcTradeInitMonitor.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommon 
 * 版本号：3.1.1.200
 * 发布时间：2017-08-21
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import "AlibcTradeCommonSDK.h"
#import "AlibcTradeMonitor.h"
#import "AlibcTradeBenchmarkable.h"

#ifndef AlibcTradeInitMonitor_h
#define AlibcTradeInitMonitor_h

@interface AlibcTradeInitMonitor : AlibcTradeMonitor

@property(strong, nonatomic, readonly) AlibcTradeTimeMeasure *allTimeMeasure;

@property(strong, nonatomic, readonly) AlibcTradeTimeMeasure *utTimeMeasure;

@property(strong, nonatomic, readonly) AlibcTradeTimeMeasure *securityTimeMeasure;

@property(strong, nonatomic, readonly) AlibcTradeTimeMeasure *authTimeMeasure;

@end


@interface AlibcTradeCommonSDK (AlibcTradeInitMonitor)

+ (void)alibc_setInitMonitor:(AlibcTradeInitMonitor *)monitor;

+ (AlibcTradeInitMonitor *)alibc_initMonitor;

+ (dispatch_group_t)alibc_initMonitorGroup;

@end

#endif
