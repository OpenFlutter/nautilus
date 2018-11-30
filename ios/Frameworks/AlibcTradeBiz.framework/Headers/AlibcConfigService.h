/*
 * AlibcConfigService.h 
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
#import "AlibcTradeTaokeParams.h"

#ifndef AlibcConfigService_h
#define AlibcConfigService_h
#define YBHPSS @"ybhpss" //全链路打通数据参数

@interface AlibcConfigService : NSObject

+ (instancetype)sharedConfig;

- (void)updateConfig;

/*包含ttid的拼装规则*/
@property(nonatomic, readonly) NSString *ttid;
@property(nonatomic, strong) NSString *isvVersion;
@property(nonatomic, copy, readwrite) NSString *channelName;
@property(nonatomic, copy, readwrite) NSString *channelType;
@property(nonatomic, readonly) NSString *channel;
@property(nonatomic, assign) BOOL isForceH5;
// TODO:
@property(nonatomic, strong) NSString *alipayRequestSender;

//全局淘客参数
@property(nonatomic, strong) AlibcTradeTaokeParams *taokeParams;
/* isvCode，tag*/
@property(atomic, strong) NSString *isvCode;

/** 系统版本信息,SDK版本 */
@property(atomic, copy) NSString *systemVersion;

//淘客打点是否使用同步换url的方式
- (BOOL)isSyncForTaoke;

//是否检测WebView支付. 如果安装了支付宝且检测支付, 使用支付宝应用完成支付; 否则, 使用WebView完成支付. 默认YES.
- (BOOL)isNeedAlipayNativeForPay;

//设置是否检测WebView支付
- (void)setNeedAlipayNativeForPay:(BOOL)need;

//是否登陆降级(不触发登陆了)
- (BOOL)isLoginDegarade;

//设置是否同步打点
- (void)setIsSyncForTaoke:(BOOL)isSync;

//双11强制降级配置
- (NSString *)double11OpenType;

//存储所有需要isv设置的配置
- (void)setIsvConfig:(id)value forKey:(NSString *)key;

- (NSString *)isvConfigForKey:(NSString *)key;

- (void)setExtUserAgent:(NSString *)extUserAgent;

- (NSString *)extUserAgent;

@end
#endif //AlibcConfigService_h
