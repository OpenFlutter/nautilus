//
// Created by mo on 2018/11/22.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>

@interface NautilusLoginService : NSObject
- (void) handleLogin:(FlutterMethodCall *)call result:(FlutterResult)result;
- (void) handleIsLogin:(FlutterMethodCall *)call result:(FlutterResult)result;
- (void) handleGetUser:(FlutterMethodCall *)call result:(FlutterResult)result;
- (void) handleLogout:(FlutterResult)result;
@end
