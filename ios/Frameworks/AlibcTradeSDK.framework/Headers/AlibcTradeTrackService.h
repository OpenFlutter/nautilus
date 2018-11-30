/*
 * AlibcTradeTrackService.h 
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

//#import <AlibcTradeBiz/AlibcTrackParams.h>

/** 内容曝光 */
extern NSString *const AlibcTradeEventId_Exposure;
/** 内容点击 */
extern NSString *const AlibcTradeEventId_ContentClick;


@interface AlibcTradeTrackService : NSObject

/**
 *  isv添加自定义ut打点..
 *
 *  @param eventId 事件名,系统自带事件名,见最上面的几个常量字符串
 *  @param Params 埋点参数
 */
+ (void)addTraceLog:(NSString *)eventId param:(AlibcTrackParams *)params;

@end
