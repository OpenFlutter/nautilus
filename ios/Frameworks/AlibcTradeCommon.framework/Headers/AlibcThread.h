/*
 * AlibcThread.h 
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

#ifndef AlibcThread_h
#define AlibcThread_h

@interface AlibcThread : NSObject

/**
 * 提交到主线程运行
 */
+ (void)foreground:(dispatch_block_t)block;

/**
 * 提交到后台主线程
 */
+ (void)backgroundMain:(dispatch_block_t)block;

+ (void)backgroundConcurrentTask:(dispatch_block_t)block;

@end

#endif
