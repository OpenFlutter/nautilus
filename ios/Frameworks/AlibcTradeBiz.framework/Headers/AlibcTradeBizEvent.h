/*
 * AlibcTradeBizEvent.h 
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


#ifndef AlibcTradeBizEvent_h
#define AlibcTradeBizEvent_h

//核心事件监听类,事件的监听和上报都通过ALiMsgBus触发
//目前包含登陆,支付事件的触发上报,

//登陆成功
#define ALIBCBIZLOGINSUCCESS @"ALI.BC.Biz.LoginSuccess"
//-(void)alibcLoginSUccess:(ALBBSession *)session

//登陆失败
#define ALIBCBIZLOGINFAIL @"ALI.BC.Biz.LoginFail"
//-(void)alibcLoginFail:(NSError *)error

//支付成功
#define ALIBCBIZLPAYSUCCESS @"ALI.BC.Biz.PaySuccess"
//-(void)alibcPaySuccess:(AlibcTradePayResult *)result context:(ALiURLBusContext*)context

//支付失败
#define ALIBCBIZLPAYFAIL @"ALI.BC.Biz.PayFail"
//-(void)alibcPayFail:(NSError *)error context:(ALiURLBusContext*)context

//webview被关闭
#define ALIBCBIZWEBVIEWCLOSE @"ALI.BC.Biz.WebviewClose"
//-(void)alibcWebviewClose:(ALiURLBusContext*)context

#endif
