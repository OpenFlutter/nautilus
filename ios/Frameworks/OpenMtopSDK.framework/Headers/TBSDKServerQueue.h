//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀/禚来强 on 13-1-28.
//  Copyright (c) 2013年 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>


/** TBSDK的请求池。
 *
 *  TBSDK的请求池，是单例模式。保存了TBSDK的所有的网络请求
 *  用户可以获取获取自己的网络请求，而不需要将网络请求保存为实例变量
 */
@interface TBSDKServerQueue : NSObject


+ (TBSDKServerQueue *)shareInstance;


//! 获取delegate_对应的符合TBSDKRequestQueueProtocol协议的对象。
- (NSArray *)getRequestForDelegate:(id)delegate_;

//! 退出符合TBSDKRequestQueueProtocol协议的对象的网络请求，并把符合TBSDKRequestQueueProtocol协议的对象的delegate设置为nil。
- (void)cancelRequestNetworkAndClearDelegateForDelegate:(id)delegate_;
 
@end

@protocol TBSDKRequestQueueProtocol <NSObject>

@required
- (void)clearDelegatesAndCancel;

@optional

@property (nonatomic, weak) id delegate;

@end