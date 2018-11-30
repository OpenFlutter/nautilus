//
// Created by mo on 2018/11/23.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>

@interface NautilusTradeHandler : NSObject
- (void)initTradeAsync:(FlutterMethodCall *)call result:(FlutterResult)result;
- (void)openItemDetail:(FlutterMethodCall *)call result:(FlutterResult)result;
- (void)openUrl:(FlutterMethodCall *)call result:(FlutterResult)result;
@end