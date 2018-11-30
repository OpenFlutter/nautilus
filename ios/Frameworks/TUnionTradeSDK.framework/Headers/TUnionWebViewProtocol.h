//
//  TUnionWebViewProtocol.h
//  TUnionSDK
//
//  Created by HuXiaoNing on 16/9/5.
//  Copyright © 2016年 HuXiaoNing. All rights reserved.
//


#ifndef TUnionWebViewProtocol_h
#define TUnionWebViewProtocol_h

NS_ASSUME_NONNULL_BEGIN

@protocol TUnionWebViewProtocol <NSObject>

@property (nullable, nonatomic, readonly, strong) NSURLRequest *request;

- (void)reload;

- (void)loadRequest:(NSURLRequest *)request;

@end

NS_ASSUME_NONNULL_END

#endif /* TUnionWebViewProtocol_h */
