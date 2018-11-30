//
//  NSString+Json.h
//  TUnion
//
//  Created by HuXiaoNing on 16/8/2.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString(TUnionJson)

- (NSDictionary *)TUnionconvertStringToDictionary:(NSError *)jsonError;

- (NSDictionary *)TUnionconvertStringToDictionary:(NSStringEncoding) encoding
                                    options:(NSJSONReadingOptions) opt
                                  jsonError:(NSError *)jsonError;

- (NSString *)TUnionAddQueryStringParameter:(NSString *)key
                                      value:(NSString *)value;

//对字符串编码，包含前面的http://都会被编码
- (NSString*)encodeString;

@end
