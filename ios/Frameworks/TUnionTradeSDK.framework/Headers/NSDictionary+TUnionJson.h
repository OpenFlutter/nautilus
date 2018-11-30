//
//  NSDictionary+Json.h
//  TUnion
//
//  Created by HuXiaoNing on 16/8/5.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary(TUnionJson)

- (NSString *)TUnionconvertDictionaryToString:(NSError *)jsonError;

- (NSString *)TUnionConvertDictionaryToString:(NSStringEncoding) encoding
                                    options:(NSJSONWritingOptions) opt
                                  jsonError:(NSError *)jsonError;
@end
