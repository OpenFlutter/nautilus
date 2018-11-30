//
//  TUnionUtProtocol.h
//  TUnionTradeSDK
//
//  Created by HuXiaoNing on 2017/1/10.
//  Copyright © 2017年 HuXiaoNing. All rights reserved.
//

#ifndef TUnionUtProtocol_h
#define TUnionUtProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol TUnionUtProtocol <NSObject>

- (void)updateUserAccount:(NSString *)nick userid:(NSString *)userid;

- (void)send:(NSString *)pageName controlName:(NSString *)ctrlName args:(nullable NSDictionary *)args;

@end

id<TUnionUtProtocol> getUtInstance();

NS_ASSUME_NONNULL_END

#endif /* TUnionUtProtocol_h */
