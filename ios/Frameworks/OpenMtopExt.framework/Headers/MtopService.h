//
//  MtopService.h
//  mtopext
//
//  Created by 亿刀/禚来强 on 16/6/15.
//  Copyright © 2016年 亿刀/禚来强. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MtopExtRequest;

@protocol MtopLoginProtocol;
@protocol MtopAuthProtocol;

NS_ASSUME_NONNULL_BEGIN

@interface MtopService : NSObject

+ (instancetype)shareInstance;

- (void)installCustomLoginModule:(id<MtopLoginProtocol>)loginHandler;

- (void)installCustomAuthModule:(id<MtopAuthProtocol>)authHandler;

- (void)async_call:(MtopExtRequest *)request;

@end

NS_ASSUME_NONNULL_END