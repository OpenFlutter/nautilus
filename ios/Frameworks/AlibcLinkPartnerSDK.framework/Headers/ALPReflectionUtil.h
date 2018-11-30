//
//  ALPReflectionUtil.h
//  ALPLinkPartnerSDK
//
//  Created by czp on 16/10/26.
//  Copyright © 2016年 czp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ALPReflectionUtil : NSObject

+ (id)getSharedInstance:(NSString *)className;

+ (id)getInstance:(NSString *)className instanceMethodName:(NSString *)instanceMethodName;

+ (id)getInstanceWithClazz:(id)clazz instanceMethodName:(NSString *)instanceMethodName;

+ (id)executeInstanceMethod:(NSString *)methodName instance:(id)instance params:(NSArray *)params;

+ (id)executeClassMethod:(NSString *)methodName clazz:(Class)clazz;

+ (id)executeInstanceMethod:(NSString *)methodName instanceAndargs:(id)instance,...;

@end
