//
//  TBSDKConnection.h
//  TBSDK
//
//  Created by 亿刀/禚来强 on 14-3-6.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKConnectionProtocol.h"


@protocol TBSDKProgressDelegate;
@protocol TBSDKConnectionDelegate;

//和ASI对应轻易不要修改
typedef enum _TBSDKNetworkErrorType {
    TBSDKConnectionFailureErrorType = 1,
    TBSDKRequestTimedOutErrorType = 2,
    TBSDKAuthenticationErrorType = 3,
    TBSDKRequestCancelledErrorType = 4,
    TBSDKUnableToCreateRequestErrorType = 5,
    TBSDKInternalErrorWhileBuildingRequestType  = 6,
    TBSDKInternalErrorWhileApplyingCredentialsType  = 7,
	TBSDKFileManagementError = 8,
	TBSDKTooMuchRedirectionErrorType = 9,
	TBSDKUnhandledExceptionError = 10,
	TBSDKCompressionError = 11,
    TBSDKACCSError = 12,
	
} TBSDKNetworkErrorType;


@interface TBSDKConnection : NSObject

@property (weak) id<TBSDKProgressDelegate>uploadProgressDelegate;

@property (nonatomic, strong) NSURL *url;

@property (nonatomic, unsafe_unretained) TBSDKCachePolicy cachePolicy;

@property (unsafe_unretained) id <TBSDKCacheDelegate> downloadCache;

@property (weak) id <TBSDKProgressDelegate> downloadProgressDelegate;

@property (unsafe_unretained, nonatomic) NSTimeInterval timeOutSeconds;

@property (nonatomic, strong) NSDictionary *responseHeaders;

@property (nonatomic, strong) NSMutableDictionary *requestHeaders;

@property (nonatomic, strong) NSError *error;

@property (nonatomic, weak) id<TBSDKConnectionDelegate>delegate;

@property (nonatomic, strong) NSMutableArray *requestCookies;

@property (nonatomic, strong) NSData *responseData;

@property (nonatomic, strong) NSString *responseString;

@property (nonatomic, unsafe_unretained) NSStringEncoding responseEncoding;

@property (assign,nonatomic) int responseStatusCode;

@property (unsafe_unretained) TBSDKPostFormat postFormat;

@property (strong) NSMutableArray *fileData;

@property (strong) NSHTTPURLResponse *response;

@property (strong) NSMutableData *postBody;

@property (atomic) BOOL isFinished;

// 打点判断是否是http
@property (nonatomic, unsafe_unretained) BOOL isHttp;

@property (nonatomic, strong) NSMutableArray *postData;

@property (nonatomic, unsafe_unretained) int postGzipSize;

// ut dataset dictionary
@property (nonatomic, strong) NSDictionary *utDict;
@property (nonatomic) CFAbsoluteTime networkEndTime;


+ (id)requestWithURL:(NSURL *)newURL;

+ (void) cancelAll;

- (id)initWithURL:(NSURL *)newURL;

- (void)setPostValue:(id<NSObject>)value forKey:(NSString *)key;

- (void)addRequestHeader:(NSString *)header value:(NSString *)value;

- (void)startAsynchronous;

- (void)startSynchronous;

- (void)clearDelegatesAndCancel;

- (void)addData:(id)data withFileName:(NSString *)fileName andContentType:(NSString *)contentType forKey:(NSString *)key;


@end
