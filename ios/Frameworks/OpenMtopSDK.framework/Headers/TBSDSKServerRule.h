//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀/禚来强  iTeam on 13-2-24.
//  Copyright (c) 2013年 亿刀/禚来强  iTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TBSDKErrorRule;


//TBSDKServer的私有方法定义
@protocol TBSDSKServerRule <NSObject>

@optional
- (void)setApiMethod:(NSString *)apiMethod;
- (void)setTbsdkError:(id<TBSDKErrorRule>)error;
- (void)setResponseData:(NSData *)responseData;

//! 网络请求开始
- (void)performDelegatStartSelector;

//! 网络请求成功
- (void)performDelegatSuccessSelector;

//! 网络请求失败
- (void)performDelegatFailSelector;

//!响应头下载完毕
- (void)performReciveResponseHeaders:(NSDictionary *)responseHeaders;

@end