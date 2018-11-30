//
//  AlibcTradeSDKDefines.h
//  AlibcTradeSDK
//
//  Created by Veight Zhou on 1/22/17.
//  Copyright © 2017 com.alibaba. All rights reserved.
//

#ifndef AlibcTradeSDKDefines_h
#define AlibcTradeSDKDefines_h

/*
 * trackParam 参数key说明
 */
#define track_scm @"scm"
#define track_pvid @"pvid"
#define track_isv_code @"isv_code"

typedef void (^AlibcTradeProcessSuccessCallback)(AlibcTradeResult *__nullable result);

typedef void (^AlibcTradeProcessFailedCallback)(NSError *__nullable error);

#endif /* AlibcTradeSDKDefines_h */
