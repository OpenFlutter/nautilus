//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀/禚来强 on 13-1-30.
//  Copyright (c) 2013年 Taobao. All rights reserved.
//

#import "TBSDKServerQueue.h"

@protocol TBSDKRequestQueueProtocol;

/** 定义了TBSDKServerQueue的私有方法
 *
 *  定义了TBSDKServerQueue的私有方法，对外不可见，只提供TBSDK内部调用
 *  外部调用可能产生不安全的行为。
 */
@interface TBSDKServerQueue (Private)


//! 添加一个TBSDKServer到请求队列
- (void)addRequest:(id<TBSDKRequestQueueProtocol>)request;

//! 从请求队列中删除一个TBSDKServer。
- (void)removeRequest:(id<TBSDKRequestQueueProtocol>)request;

@end