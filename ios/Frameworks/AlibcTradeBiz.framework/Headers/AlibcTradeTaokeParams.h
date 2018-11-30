/*
 * AlibcTradeTaokeParams.h 
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

#ifndef AlibcTradeTaokeParams_h
#define AlibcTradeTaokeParams_h

/**
 *  统一的 key 写法
 */
static NSString *const AlibcTradeTaokeParamsAdzoneId = @"adzoneid";
static NSString *const AlibcTradeTaokeParamsPid = @"pid";
static NSString *const AlibcTradeTaokeParamsUnionID = @"unionId";
static NSString *const AlibcTradeTaokeParamsSubPid = @"subpid";

/** 淘客参数 */
@interface AlibcTradeTaokeParams : NSObject
/** 淘客ID */
@property(nonatomic, copy) NSString *adzoneId;
@property(nonatomic, copy) NSString *pid;

/** */
@property(nonatomic, copy) NSString *unionId;
/** */
@property(nonatomic, copy) NSString *subPid;

@property(nonatomic, strong) NSDictionary *extParams;

@end

#endif
