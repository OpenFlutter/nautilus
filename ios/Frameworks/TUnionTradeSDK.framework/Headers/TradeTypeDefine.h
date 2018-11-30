//
//  Header.h
//  TUnionTradeSDK
//
//  Created by liufuyin on 2017/6/30.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#ifndef TradeTypeDefine_h
#define TradeTypeDefine_h


typedef NS_ENUM(NSUInteger, TUnionABTestStatus) {
    TUNION_ABTEST_INVALID = 1,   //没有配置abtest
    TUNION_ABTEST_YES = 2,      //ABTest配置为true,表示强制手淘跳转
    TUNION_ABTEST_NO = 3        //ABTest配置为false，表示强制H5跳转
};

typedef NS_ENUM(NSUInteger, TUnionJumpPageType) {
    JUMP_WITH_H5 = 1,       //用H5进行页面跳转
    JUMP_WITH_NATIVE = 2,   //唤起手淘进行页面跳转
    JUMP_WITH_BROWSER = 3   //用系统浏览器进行跳转
};


#endif /* Header_h */
