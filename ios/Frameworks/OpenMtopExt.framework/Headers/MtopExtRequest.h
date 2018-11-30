//
//  MtopExtRequest.h
//  mtopext
//
//  Created by 亿刀/禚来强 on 16/6/13.
//  Copyright © 2016年 亿刀/禚来强. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MtopExtRequest;
@class MtopExtResponse;

typedef void (^MtopExtRequestStarted)(MtopExtRequest* request);

typedef void (^MtopExtRequestFailed)(MtopExtResponse* response);

typedef void (^MtopExtRequestSucceed)(MtopExtResponse* response);

typedef enum {
    
    /* 标记用的，请不要用 */
    MtopSessionExpiredOptionDummy                        = -1,
    
    /* Session失效时，什么都不做 */
    MtopSessionExpiredOptionNone                         = 0,
    
    /* Session失效时，只做Auto Login */
    MtopSessionExpiredOptionAutoLogin                    = 1,
    
    /* Session失效时，先Auto Login，如果Auto Login失败，唤起登录界面 */
    MtopSessionExpiredOptionAutoLoginAndManualLogin      = 2
    
} MtopSessionExpiredOption;

typedef enum {
    
    /* 标记用的，请不要用 */
    MtopAuthExpiredOptionDummy                        = -1,
    
    /* Session失效时，什么都不做 */
    MtopAuthExpiredOptionNone                         = 0,
    
    /* Session失效时，只做Auto Login */
    MtopAuthExpiredOptionAutoAuth                    = 1,
    
    /* Session失效时，先Auto Login，如果Auto Login失败，唤起登录界面 */
    MtopAuthExpiredOptionAutAuthAndManualAuth     = 2
    
} MtopAuthExpiredOption;

@interface MtopExtRequest : NSObject

@property(assign, nonatomic) BOOL                                               needLogin;

@property(assign, nonatomic) BOOL                                               needAuth;

@property(assign, nonatomic) BOOL                                               needWUA;

@property(assign, nonatomic) MtopSessionExpiredOption                           sessionExpiredOption;

@property(assign, nonatomic) MtopAuthExpiredOption                              authExpiredOption;

@property (nonatomic, unsafe_unretained) NSTimeInterval                         timeOutSeconds;

@property(copy, atomic) MtopExtRequestStarted                                   startedBlock;

@property(copy, atomic) MtopExtRequestFailed                                    failedBlock;

@property(copy, atomic) MtopExtRequestSucceed                                   succeedBlock;

@property (nonatomic, strong, readonly) NSString                                *apiName;

@property (nonatomic, strong, readonly) NSString                                *apiVersion;

@property (nonatomic, strong, readonly) NSString                                *requestID;

@property (nonatomic, strong, readonly) NSDictionary                            *requestHeaders;

@property (nonatomic, strong) NSString                                          *customHost;

@property(assign, atomic, readonly) BOOL                                        isCanceled;

@property (nonatomic, strong) NSDictionary                                      *userInfo;

@property (nonatomic, strong, readonly) NSString                                *bizID;


- (id)initWithApiName:(nullable NSString *)apiName apiVersion:(nullable NSString *)apiVersion bizID:(nullable NSString *)bizID;

- (void)addHttpHeader:(NSString *)value forKey:(NSString *)key;

- (void)addBizParameter:(id)value forKey:(NSString *)key;

- (void)addBizParameters:(NSDictionary *)kvs;

- (void)removeBizParameter:(NSString *)key;

- (void)useHttpPost;

- (BOOL)isUseHttpPost;

- (void)cancel;

- (NSDictionary *)getBizParameters;

@end

NS_ASSUME_NONNULL_END
