/*
 * AlibcLoginBridge.h 
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
#import <UIKit/UIKit.h>

#ifndef AlibcLoginBridge_h
#define AlibcLoginBridge_h

@interface AlibcLoginBridge : NSObject


/**
 登录模块标准初始化接口
 */
+ (void)initLogin;


/**
 登录模块极简版初始化接口
 
 @brief 极简版没有依赖安全模块, 需要手动传入 Appkey

 @param appkey appkey
 */
+ (void)initLoginWithAppkey:(NSString *)appkey;

+ (BOOL)isLoginSvrAvaleable;

+ (void)showLogin:(UIViewController *)parentController
  successCallback:(void (^)(NSString *userID))onSuccess
   failedCallback:(void (^)(NSError *error))onFailure;

+ (void)logout;

+ (void)setEnvironment:(AlibcEnvironment)env;

/**
 是否是登陆URL
 */
+ (BOOL)isLoginURL:(NSString *)url;

/**
 是否是登出URL
 */
+ (BOOL)isLogoutUrl:(NSString *)url;

/**
 是否是手淘跳回url
 */
+ (BOOL)isTBBackUrl:(NSString *)url;

/**
 手淘跳转回来，拿到url调用
 */
+ (void)loginByURL:(NSURL *)url;

@end

#endif
