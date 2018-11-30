/*
 * AlibcMultiDelegates.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommon 
 * 版本号：3.1.1.200
 * 发布时间：2017-08-21
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AlibcMultiDelegateEnumerator;

@interface AlibcMultiDelegates<ObjectType> : NSObject

- (void)addDelegate:(nullable ObjectType)aDelegate;

- (void)removeDelegate:(nullable ObjectType)aDelegate;

- (void)addDelegate:(nullable ObjectType)delegate delegateQueue:(nullable dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(nullable ObjectType)delegate delegateQueue:(nullable dispatch_queue_t)delegateQueue;

- (void)removeAllDelegates;

- (NSUInteger)count;
- (NSUInteger)countOfClass:(Class)aClass;
- (NSUInteger)countForSelector:(SEL)aSelector;

- (BOOL)hasDelegateThatRespondsToSelector:(SEL)aSelector;

- (AlibcMultiDelegateEnumerator *)delegateEnumerator;

@end


@interface AlibcMultiDelegateEnumerator : NSObject

- (NSUInteger)count;
- (NSUInteger)countOfClass:(Class)aClass;
- (NSUInteger)countForSelector:(SEL)aSelector;

- (BOOL)getNextDelegate:(id _Nullable * _Nullable)delegatePointer delegateQueue:(dispatch_queue_t _Nullable * _Nullable)queuePointer;
- (BOOL)getNextDelegate:(id _Nullable * _Nullable)delegatePointer delegateQueue:(dispatch_queue_t _Nullable * _Nullable)queuePointer ofClass:(Class)aClass;
- (BOOL)getNextDelegate:(id _Nullable * _Nullable)delegatePointer delegateQueue:(dispatch_queue_t _Nullable * _Nullable)queuePointer forSelector:(SEL)aSelector;

@end

NS_ASSUME_NONNULL_END
