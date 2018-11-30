#import <Flutter/Flutter.h>
#import "NautilusLoginService.h"
#import "NautilusTradeHandler.h"
#import <AlibcTradeSDK/AlibcTradeSDK.h>
@interface NautilusPlugin : NSObject<FlutterPlugin>

- (instancetype)initWithRegistrar:(NSObject <FlutterPluginRegistrar> *)registrar;
@end
