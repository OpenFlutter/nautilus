//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀/禚来强 on 13-3-25.
//  Copyright (c) 2013年 yidao. All rights reserved.
//


#ifdef __cplusplus
extern "C" {
#endif
    
#import <Foundation/Foundation.h>
    
    /** 开关openSDK的log */
    void openSDKSwitchLog(BOOL logCtr);
    
    /** 打印log */
    void openSDKNSLog(NSString *formate, ...);
    

//#define MLog(formate, args...) NSLog(formate, args...)// openSDKNSLog(@"%s %d: " formate, __FUNCTION__, __LINE__, ##args)
    
//#ifdef DEBUG_MODE
#define MLog( s, ... ) openSDKNSLog( @"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
//#else
//#define DLog( s, ... )
//#endif
    
#ifdef __cplusplus
}
#endif