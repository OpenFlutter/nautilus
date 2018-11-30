/*
 * AlibcTradeSDK.h 
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
#import <AlibcTradeCommon/AlibcTradeCommon.h>
#import <AlibcTradeBiz/AlibcTradeBiz.h>
#import "AlibcTradePageFactory.h"
#import "AlibcTradeService.h"
#import "AlibcTradeShowParams.h"


@interface AlibcTradeSDK : NSObject

/**
 *  AlibcTradeSDK 的单例对象
 */
+ (instancetype)sharedInstance;

/**
 *  !!!: 已弃用
 *  初始化函数,初始化成功后方可正常使用SDK中的功能
 *
 *  @param appKey    该App对应的AppKey
 *  @param onSuccess 初始化成功的回调
 *  @param onFailure 初始化失败的回调
 */
/*
- (void)asyncInit:(NSString*)appKey
          success:(void (^)())onSuccess
          failure:(void (^)(NSError *error))onFailure DEPRECATED_ATTRIBUTE;
*/

/**
 *  初始化函数,初始化成功后方可正常使用SDK中的功能
 *
 *  @param onSuccess 初始化成功的回调
 *  @param onFailure 初始化失败的回调
 */
- (void)asyncInitWithSuccess:(void (^)())onSuccess
                     failure:(void (^)(NSError *error))onFailure;

/**
 *  获取service对象,该对象包含大部分Trade相关的方法
 */
- (id <AlibcTradeService>)tradeService;

/**
 * ============================================================================
 *  用于处理其他App的回跳
 *
 *  @param url 需要进行判断的URL对象
 *
 *  @return 是否被SDK进行处理
 *
 *  该接口已经启用, 请使用
 *  iOS 7&8: -[AlibcTradeSDK application:openURL:sourceApplication:annotation:]
 *  iOS 9+: -[AlibcTradeSDK application:openURL:options:] => iOS 9+
 *  替代
 * ============================================================================
 */
/* - (BOOL)handleOpenURL:(NSURL *)url; */


/**
 * App 回跳处理, 适用于 iOS 9 以下的回调接口
 
 @param application application
 @param url url
 @param sourceApplication sourceApplication
 @param annotation annotation
 @return handled or nor
 */
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

/**
 * App 回跳处理, 适用于 iOS 9 起的回调接口
 
 @param annotation annotation
 @param url url
 @param options options
 @return handled or nor
 */
- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<NSString *, id> *)options NS_AVAILABLE_IOS(9_0);

@end

@interface AlibcTradeSDK (Settings)

- (void)setDebugLogOpen:(BOOL)isDebugLogOpen;

/**
 *  设置环境
 */
- (void)setEnv:(AlibcEnvironment)env;

/**
 *  设置全局配置,是否强制使用h5
 *
 *  @param isForceH5 是否强制使用h5,show接口的AlibcTradeShowParams参数优先级比这里高,AlibcTradeShowParams设置AlibcOpenTypeNative,依然可以跳手淘..
 */
- (void)setIsForceH5:(BOOL)isForceH5;

/*
 *  设置是否对淘客使用同步打点
 *  默认的淘客打点方式,sdk会自己选择合适的方式,调用该接口与否不影响打点,建议开发者不要调用自己配置
 *  只有跟阿里妈妈申请了高分润的才需要设为同步
 *
 *  @param isSync 是否对淘客使用同步打点
 */
- (void)setIsSyncForTaoke:(BOOL)isSync;

/**
 *  设置三方App版本,可用于标识App版本
 *
 *  @param version 版本字段
 */
- (void)setIsvVersion:(NSString *)version;

/**
 *  设置App标识字段,和isvcode同义,可用于区分使用本SDK的具体三方App
 *
 *  @param code isv code 字段
 */
- (void)setISVCode:(NSString *)code;

/**
 *  设置默认淘客参数
 *
 *  @param param 传入一个配置好的AlibcTradeTaokeParams作为默认淘客参数,详见 AlibcTradeTaokeParams.h
 */

- (void)setTaokeParams:(AlibcTradeTaokeParams *)param;

/**
 *  设置渠道信息,渠道专享价专用.
 *
 *  @param type 渠道类型
 *  @param name 渠道名
 */
- (void)setChannel:(NSString *)type name:(NSString *)name;

/**
 *  开启接口免授权模式,
 *  请不要随便设置,没有在后台申请相关的权限的,开启后会导致网络请求失败
 *
 */
- (void)enableAuthVipMode;

/**
 *  设置是否需要 Native AliPay 接口
 *
 *  @param shouldUseAlipay 是否需要 Native AliPay 接口
 */
- (void)setShouldUseAlipayNative:(BOOL)shouldUseAlipayNative;

@end
