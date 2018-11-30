#import "NautilusPlugin.h"


@implementation NautilusPlugin

NautilusLoginService *_loginService;
NautilusTradeHandler *_tradeHandler;


+ (void)registerWithRegistrar:(NSObject <FlutterPluginRegistrar> *)registrar {
    FlutterMethodChannel *channel = [FlutterMethodChannel
            methodChannelWithName:@"com.jarvanmo/nautilus"
                  binaryMessenger:[registrar messenger]];
    NautilusPlugin *instance = [[NautilusPlugin alloc] initWithRegistrar:registrar];
    [registrar addMethodCallDelegate:instance channel:channel];
}

- (instancetype)initWithRegistrar:(NSObject <FlutterPluginRegistrar> *)registrar {
    self = [super init];

    if (self) {
        _loginService = [[NautilusLoginService alloc] init];
        _tradeHandler = [[NautilusTradeHandler alloc] init];
    }

    return self;
}

- (void)handleMethodCall:(FlutterMethodCall *)call result:(FlutterResult)result {
    if ([@"initTradeAsync" isEqualToString:call.method]) {
        [_tradeHandler initTradeAsync:call result:result];
    } else if ([@"login" isEqualToString:call.method]) {
        [_loginService handleLogin:call result:result];
    } else if ([@"isLogin" isEqualToString:call.method]) {
        [_loginService handleIsLogin:call result:result];
    } else if ([@"getUser" isEqualToString:call.method]) {
        [_loginService handleGetUser:call result:result];
    } else if ([@"logout" isEqualToString:call.method]) {
        [_loginService handleLogout:result];
    } else if([@"openItemDetail" isEqualToString:call.method]){
        [_tradeHandler openItemDetail:call result:result];
    } else if([@"openUrl" isEqualToString:call.method]){
        [_tradeHandler openUrl:call result:result];
    }else{
        result(FlutterMethodNotImplemented);
    }
}



@end
