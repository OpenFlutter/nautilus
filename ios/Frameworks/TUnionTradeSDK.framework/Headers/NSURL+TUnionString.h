//
//  String.h
//  TUnionSDK
//
//  Created by HuXiaoNing on 16/8/16.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL(TUnionString)

//根据给定的Url，生成NSUrl对象，支持中文
+ (instancetype)URLWithStringSupportPrcentEncoding:(NSString *)URLString;

//取NSUrl中的Domain信息
- (NSString *)tunionDomain;
@end
