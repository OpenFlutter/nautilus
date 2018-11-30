//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀/禚来强 on 13-2-19.
//  Copyright (c) 2013年 亿刀/禚来强. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol TBSDKErrorRule <NSObject>

@required
@property (nonatomic, strong) NSString                                          *errorCode;

@property (nonatomic, strong) NSString                                          *msg;

@optional
@property (nonatomic, strong)  NSString                                         *sub_code;

@property (nonatomic, strong)  NSString                                         *sub_msg;

@property (nonatomic, strong)  NSDictionary                                     *args;

@property (nonatomic, strong)  NSDictionary                                     *raw;

//开发调试使用的参数，用户存放代码出错的位置(__FUNCTION__, __LINE__)
@property (nonatomic, strong) NSString                                          *errorLocation;

@property (nonatomic, strong) NSError                                           *error;

@end
