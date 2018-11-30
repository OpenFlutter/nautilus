//
//  TUnionCache.h
//  bunny
//
//  Created by knight on 16/8/6.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TUnionCache : NSObject
+ (nonnull instancetype)sharedInstance;

- (nonnull instancetype)initWithCostLimit:(NSInteger) costLimit
                       countLimit:(NSInteger) countLimit
                             name:(nullable NSString *) name;

- (nonnull instancetype)initWithCostLimit:(NSInteger) costLimit
                       countLimit:(NSInteger) countLimit;

- (nullable id)objectForKey:(nonnull id<NSCopying>)key;
- (void)setObject:(nonnull id<NSCoding>)obj forKey:(nonnull id<NSCopying>)key; // 0 cost
- (void)setObject:(nonnull id<NSCoding>)obj forKey:(nonnull id<NSCopying>)key cost:(NSUInteger)g;
- (void)removeObjectForKey:(nonnull id<NSCopying>)key;

- (void)removeAllObjects;
@end
