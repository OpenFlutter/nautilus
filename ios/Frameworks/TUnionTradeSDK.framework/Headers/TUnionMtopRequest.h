//
//  TUnionMtopRequest.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/1/20.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TUnionMtopRequest : NSObject

@property(nonnull, nonatomic, strong) NSString * api;
@property(nonnull, nonatomic, strong) NSString * version;
@property(nonatomic) BOOL needLogin;             //默认值:NO
@property(nonatomic) BOOL needAuth;              //默认值:NO
@property(nonatomic) BOOL needWUA;    //是否需要人机识别,默认是NO

@end
