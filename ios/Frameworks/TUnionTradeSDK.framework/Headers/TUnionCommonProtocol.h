//
//  TUnionCommonProtocol.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/1/12.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#ifndef TUnionCommonProtocol_h
#define TUnionCommonProtocol_h

@protocol TUnionCommonProtocol <NSObject>

- (NSString *)getUtdid;

- (NSString *)getAppkey;

- (NSString *)getAdzoneId;

@end

id<TUnionCommonProtocol> getCommonInstance();

#endif /* TUnionCommonProtocol_h */
