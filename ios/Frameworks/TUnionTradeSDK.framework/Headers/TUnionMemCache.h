//
//  TUnionMemCache.h
//  bunny
//
//  Created by knight on 16/8/6.
//  Copyright © 2016年 alimama. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TUnionMemCache : NSCache
- (nullable id)objectForKey:(nonnull id<NSCopying>)key;
- (void)setObject:(nonnull id<NSCoding>)obj forKey:(nonnull id<NSCopying>)key; // 0 cost
- (void)setObject:(nonnull id<NSCoding>)obj forKey:(nonnull id<NSCopying>)key cost:(NSUInteger)g;
- (void)removeObjectForKey:(nonnull id<NSCopying>)key;

- (void)removeAllObjects;

@end
