//
//  aluEnvConfig.h
//  AliUniversalAccount
//
//  Created by ethan on 12/14/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/** 环境 */
typedef NS_ENUM (NSUInteger, ALBBEnvironment) {
    /** 测试环境 */
    ALBBEnvironmentDaily,
    /** 预发环境 */
    ALBBEnvironmentPreRelease,
    /** 线上环境 */
    ALBBEnvironmentRelease,
};

@interface ALBBEnvConfig : NSObject

@property (nonatomic, strong)NSString *additional;

+ (instancetype)shareInstance;

- (void) setGWServerSettings:(ALBBEnvironment) env;

- (BOOL) isDaily;
- (BOOL) isPre;
- (BOOL) isOnline;
- (void)setSecAdditional:(NSString *)additional;

@end
