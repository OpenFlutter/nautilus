//
//  MtopError.h
//  mtopext
//
//  Created by 亿刀/禚来强 on 16/6/15.
//  Copyright © 2016年 亿刀/禚来强. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MtopError : NSObject

// 错误码
@property(strong, nonatomic) NSString                                           *code;

// 错误提示信息
@property(strong, nonatomic) NSString                                           *msg;

// 原始的错误
@property(strong, nonatomic) NSError                                            *rawError;

@end