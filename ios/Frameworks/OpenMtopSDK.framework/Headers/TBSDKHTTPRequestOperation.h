//
//  NWHTTPRequestOperation.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 5/8/15.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//

#import "TBSDKURLConnectionOperation.h"

@interface TBSDKHTTPRequestOperation : TBSDKURLConnectionOperation

- (void)setCompletionBlockWithSuccess:(void (^)(TBSDKHTTPRequestOperation *operation, id responseObject))success
                              failure:(void (^)(TBSDKHTTPRequestOperation *operation, NSError *error))failure;

@end