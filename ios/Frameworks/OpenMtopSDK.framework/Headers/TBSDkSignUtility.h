//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀/禚来强 on 13-7-31.
//  Copyright (c) 2013年 亿刀/禚来强. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TBSDkSignUtility : NSObject

+ (TBSDkSignUtility *)shareInstance;

+ (NSString *)getMtopSignWithAppkey:(NSString *)appkey
                        withApiName:(NSString *)apiName
                     withApiVersion:(NSString *)apiVersion
                           withData:(NSDictionary *)data
                         withHeader:(NSDictionary *)headers;

/*!
 * 用sercet md5字符串value
 * @param value
 * @return
 *              MD5
 */
+ (NSString*) md5: (NSString*) appkey value: (NSString*) value;
+ (NSString*) md5: (NSString*) value;
/*!
 *
 *
 *
 */
- (void) removeSecurity: (NSString*) key;

/*!
 *
 *
 *
 */
- (void) addSecurity: (NSString*) key;

@end
