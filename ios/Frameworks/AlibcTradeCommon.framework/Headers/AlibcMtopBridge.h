/*
 * AlibcMtopBridge.h 
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
#import "AlibcConfig.h"

#ifndef AlibcMtopBridge_h
#define AlibcMtopBridge_h

@class AlibcNetPacket;
@class MtopError;
@class AlibcNetError;

@interface AlibcMtopBridge : NSObject

+ (BOOL)isAvailable;

+ (void)openSDKSwitchLog:(BOOL)logCtr;

+ (void)initMtop;

+ (void)setEnvironment:(AlibcEnvironment)env;

+ (void)setTTID:(NSString *)ttid;

@end

@protocol AlibcMtopAdapter <NSObject>

- (void)openSDKSwitchLog:(BOOL)logCtr;

- (void)initMtop;

- (BOOL)performSend:(AlibcNetPacket *)packet;

- (AlibcNetError *)proccessMtopError:(MtopError *)sdkError;

- (BOOL)shouldRetry:(NSError *)error;

- (void)setTTID:(NSString *)ttid;

- (void)setEnvironment:(AlibcEnvironment)env;

@end

#endif
