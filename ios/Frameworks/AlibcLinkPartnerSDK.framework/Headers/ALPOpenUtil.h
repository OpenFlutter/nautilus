//
//  ALPOpenUtil.h
//  ALPLinkPartnerSDK
//
//  Created by czp on 16/9/22.
//  Copyright © 2016年 czp. All rights reserved.
//

#import "ALPJumpParam.h"
#import <UIKit/UIKit.h>

@interface ALPOpenUtil : NSObject

/**
 *  把dictionary转为json
 *
 */
+ (NSString *)pareseToJSONWithDictionary:(NSDictionary *)dictionary;

/**
 *  把json转为dictionary
 *
 */
+ (NSDictionary *)parseToDictionaryWithJSON:(NSString *)json;


+ (NSString *)encodeALLWithURL:(NSString *)url;

/**
 *  query转Dictionary
 */
+ (NSDictionary*)queryDictionaryFromURL:(NSString*)urlString;

/**
 *  Dictionary转query
 *
 *  @param dic 字典
 *
 *  @return query字符串
 */
+ (NSString *)queryStringFromDictionary:(NSDictionary *)dic;

/**
 *  md5加密算法,传入待加密string
 */
+ (NSString *)encodeToMD5:(NSString *)string;

/**
 * 获取ttid
 */
+ (NSString *)getTtid;

/**
 *  当前viewController
 *
 *  @return 当前viewController
 */
+ (UIViewController *)currentVC;

/**
 * urldecode
 */
+ (NSString *)urlDecoded:(NSString *)string;

/*
 * 转换为base64字符串
 */
+ (NSString *)base64EncodedWithString:(NSString*)str;

@end
