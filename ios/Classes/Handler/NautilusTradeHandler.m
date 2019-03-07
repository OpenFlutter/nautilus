//
// Created by mo on 2018/11/23.
//

#import "NautilusTradeHandler.h"
#import <AlibcTradeSDK/AlibcTradeSDK.h>
#import "NautilusStringUtil.h"
#import "NautilusConstants.h"

@implementation NautilusTradeHandler

- (void)initTradeAsync:(FlutterMethodCall *)call result:(FlutterResult)result {
    BOOL debuggable = [call.arguments[@"debuggable"] boolValue];

    NSString *version = call.arguments[@"version"];

    [[AlibcTradeSDK sharedInstance] setDebugLogOpen:debuggable];//开发阶段打开日志开关，方便排查错误信息
    if (![NautilusStringUtil isBlank:version]) {
        [[AlibcTradeSDK sharedInstance] setIsvVersion:version];
    }


    [[AlibcTradeSDK sharedInstance] asyncInitWithSuccess:^{
        result(@{nautilusKeyPlatform: nautilusKeyIOS, nautilusKeyResult: @YES});
    }                                            failure:^(NSError *error) {
        result(@{nautilusKeyPlatform: nautilusKeyIOS, nautilusKeyResult: @NO, nautilusKeyErrorCode: @(error.code), nautilusKeyErrorMessage: error.description});
    }];

}

- (void)openItemDetail:(FlutterMethodCall *)call result:(FlutterResult)result {
    NSString *itemID = call.arguments[@"itemID"];
    id <AlibcTradePage> page = [AlibcTradePageFactory itemDetailPage:itemID];
    [self OpenByPage:page call:call result:result];
}

- (void)openUrl:(FlutterMethodCall *)call result:(FlutterResult)result {
    NSString *pageUrl = call.arguments[@"pageUrl"];
    id <AlibcTradePage> page = [AlibcTradePageFactory page:pageUrl];
    [self OpenByPage:page call:call result:result];
}

- (void)OpenByPage:(id <AlibcTradePage>)page call:(FlutterMethodCall *)call result:(FlutterResult)result {
    UIViewController *rootViewController =
            [UIApplication sharedApplication].delegate.window.rootViewController;

    NSString *backUrl = call.arguments[@"backUrl"];
    BOOL needPush = [call.arguments[@"needPush"] boolValue];
    NSNumber *type = call.arguments[@"openType"];
    NSNumber *nativeFailedMode = call.arguments[@"openNativeFailedMode"];

    AlibcTradeShowParams *showParam = [[AlibcTradeShowParams alloc] init];
    showParam.openType = [self intToAlibcOpenType:[type intValue]];
//    showParam.backUrl=@"tbopen23082328:https://h5.m.taobao.com";
    showParam.backUrl = backUrl;
    showParam.isNeedPush = needPush;
    showParam.nativeFailMode = [self intToNativeFailMode:[nativeFailedMode intValue]];

//    showParam.linkKey = @"tmall_scheme";//暂时拉起天猫
    showParam.linkKey = call.arguments[@"schemeType"];
//    showParam.linkKey = @"dingding_scheme";//暂时拉起天猫


    NSInteger openResultCode = -1;

    AlibcTradeProcessSuccessCallback _onTradeSuccess = ^(AlibcTradeResult *tradeProcessResult) {

        if (tradeProcessResult.result == AlibcTradeResultTypePaySuccess) {
            result(@{
                    @"openResultCode": @(openResultCode),
                    nautilusKeyPlatform: nautilusKeyIOS,
                    nautilusKeyResult: @YES,
                    @"tradeResultType": @0,
                    @"paySuccessOrders": [tradeProcessResult payResult].paySuccessOrders,
                    @"payFailedOrders": [tradeProcessResult payResult].payFailedOrders
            });
        } else if (tradeProcessResult.result == AlibcTradeResultTypeAddCard) {

            result(@{
                    @"openResultCode": @(openResultCode),
                    nautilusKeyPlatform: nautilusKeyIOS,
                    nautilusKeyResult: @YES,
                    @"tradeResultType": @1,
            });
        } else{
            result(@{
                    @"openResultCode": @(openResultCode),
                    nautilusKeyPlatform: nautilusKeyIOS,
                    nautilusKeyResult: @YES,
                    @"tradeResultType": @-1,
            });
        }

    };


    AlibcTradeProcessFailedCallback _onTradeFailure = ^(NSError *error) {
//        退出交易流程

        NSDictionary *infor = [error userInfo];
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:infor options:NSJSONWritingPrettyPrinted error:&error];

        NSString *jsonString = @"";

        if (jsonData) {
            jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];

        }

        result(@{
                @"openResultCode": @(openResultCode),
                nautilusKeyPlatform: nautilusKeyIOS,
                nautilusKeyResult: @NO,
                nautilusKeyErrorCode: @(error.code),
                nautilusKeyErrorMessage: jsonString,
        });

    };

    AlibcTradeTaokeParams *taoKeParams = nil;
    taoKeParams = [self buildTaoKeParam:call];

    NSDictionary *extParams = call.arguments[@"extParams"];
    if ([extParams isKindOfClass:[NSNull class]]) {
        extParams = nil;
    }

    openResultCode = [[AlibcTradeSDK sharedInstance].tradeService show:rootViewController page:page showParams:showParam taoKeParams:taoKeParams trackParam:extParams tradeProcessSuccessCallback:_onTradeSuccess tradeProcessFailedCallback:_onTradeFailure];


}

- (AlibcTradeTaokeParams *)buildTaoKeParam:(FlutterMethodCall *)call {


    if (call.arguments[@"taoKeParams"] == nil || [call.arguments[@"taoKeParams"] isKindOfClass:[NSNull class]]) {
        return nil;
    }

    AlibcTradeTaokeParams *taoke = [[AlibcTradeTaokeParams alloc] init];
    NSDictionary *taoKeParams = call.arguments[@"taoKeParams"];

    taoke.pid =  (taoKeParams[@"taoKeParamsPid"] == (id) [NSNull null]) ? nil : taoKeParams[@"taoKeParamsPid"];
    taoke.subPid = (taoKeParams[@"taoKeParamsSubPid"] == (id) [NSNull null]) ? nil : taoKeParams[@"taoKeParamsSubPid"];
    taoke.unionId = (taoKeParams[@"taoKeParamsUnionId"] == (id) [NSNull null]) ? nil : taoKeParams[@"taoKeParamsUnionId"];
    taoke.adzoneId = (taoKeParams[@"taoKeParamsAdzoneId"] == (id) [NSNull null]) ? nil : taoKeParams[@"taoKeParamsAdzoneId"];
    taoke.extParams = (taoKeParams[@"taoKeParamsExtParams"] == (id) [NSNull null]) ? nil : taoKeParams[@"taoKeParamsExtParams"];
    return taoke;


}

- (AlibcOpenType)intToAlibcOpenType:(int)type {
    AlibcOpenType openType = AlibcOpenTypeAuto;
    switch (type) {
        case 0:
            openType = AlibcOpenTypeAuto;
            break;
        case 1:
            openType = AlibcOpenTypeNative;
            break;
        case 2:
            openType = AlibcOpenTypeH5;
            break;

        default:
            break;
    }
    return openType;
}

- (AlibcNativeFailMode)intToNativeFailMode:(int)mode {
    AlibcNativeFailMode openType = AlibcNativeFailModeJumpH5;
    switch (mode) {
        case 0:
            openType = AlibcNativeFailModeJumpH5;
            break;
        case 1:
            openType = AlibcNativeFailModeJumpDownloadPage;
            break;
        case 2:
            openType = AlibcNativeFailModeJumpBrowser;
            break;
        case 3:
            openType = AlibcNativeFailModeNone;
            break;
        default:
            break;
    }
    return openType;

}
@end