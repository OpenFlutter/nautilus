//
//  ALPAppShare.h
//  AlibcLinkPartnerSDK
//
//  Created by czp on 17/3/9.
//  Copyright © 2017年 czp. All rights reserved.
//

#import <UIKit/UIKit.h>

// type定义
#define ALIBC_APPSHARE_TYPE_ID          @"id"
#define ALIBC_APPSHARE_TYPE_RED         @"red"
#define ALIBC_APPSHARE_TYPE_DEEP        @"deep"

@interface ALPAppShare : NSObject

/**
 * 写入共享的信息
 * @info 具体信息(info 中内容必须是可序列化类型，参考NSKeyedArchiver)
 * @type 类型
 *
 */
+ (void)writeInfo:(NSDictionary*)info byType:(NSString*)type;

/**
 * 删除共享的信息
 * @type 类型
 */
+ (void)removeInfoByType:(NSString*)type;

/**
 * 读取共享信息
 * @type 类型
 * @return 具体信息
 */
+ (NSDictionary*)readInfoByType:(NSString*)type;

@end

