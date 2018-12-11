//
// Created by mo on 2018/11/22.
//

#import "NautilusLoginService.h"
#import "NautilusConstants.h"


@implementation NautilusLoginService


- (void)handleGetUser:(FlutterMethodCall *)call result:(FlutterResult)result {
    NSDictionary *user = nil;
    BOOL isLogin = [[ALBBSession sharedInstance] isLogin];
    if (isLogin) {
        
        user = @{
                @"avatarUrl": [[ALBBSession sharedInstance]getUser].avatarUrl,
                @"nick": [[ALBBSession sharedInstance]getUser].nick,
                @"openId": [[ALBBSession sharedInstance]getUser].openId,
                @"openSid": [[ALBBSession sharedInstance]getUser].openSid,
                @"topAccessToken": [[ALBBSession sharedInstance]getUser].topAccessToken,
                @"topAuthCode":[[ALBBSession sharedInstance]getUser].topAuthCode,
                
        };
    }
    result(@{
            nautilusKeyPlatform: nautilusKeyIOS,
            nautilusKeyResult: @(isLogin),
            @"user": user
    });
}

- (void)handleIsLogin:(FlutterMethodCall *)call result:(FlutterResult)result {
    result( @([[ALBBSession sharedInstance] isLogin]));
}

- (void)handleLogin:(FlutterMethodCall *)call result:(FlutterResult)result {
    UIViewController *rootViewController =
            [UIApplication sharedApplication].delegate.window.rootViewController;

    [[ALBBSDK sharedInstance] auth:rootViewController successCallback:^(ALBBSession *session) {
        result(@{
                nautilusKeyPlatform: nautilusKeyIOS,
                nautilusKeyResult: @YES,
                @"user": @{
                        @"avatarUrl": [session getUser].avatarUrl,
                        @"nick": [session getUser].nick,
                        @"openId": [session getUser].openId,
                        @"openSid": [session getUser].openSid,
                        @"topAccessToken": [session getUser].topAccessToken,
                        @"topAuthCode":[session getUser].topAuthCode,
                }
        });
    }              failureCallback:^(ALBBSession *session, NSError *error) {
        result(@{
                nautilusKeyPlatform: nautilusKeyIOS,
                nautilusKeyResult: @NO,
                nautilusKeyErrorCode: @(error.code),
                nautilusKeyErrorMessage: error.description
        });
    }];

}


- (void)handleLogout:(FlutterResult)result {
    [[ALBBSDK sharedInstance] logout];
    result(@{
        nautilusKeyPlatform:nautilusKeyIOS,
        nautilusKeyResult:@YES
    });
}

- (NSString *)jsonClassConvertToJsonStringWithJsonClass:(id)jsonClass {
    NSString *resultString;

    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:jsonClass options:NSJSONWritingPrettyPrinted error:&error];
    if (error == nil) {
        resultString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }

    return resultString;
}

@end
