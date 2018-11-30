//
//  ALPJumpFailedStrategy.h
//  AlibcLinkPartnerSDK
//
//  Created by czp on 16/11/24.
//  Copyright © 2016年 czp. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ALPJumpFailedMode)
{
    ALPJumpFailedModeOpenH5           = 0,//降级到h5（默认）
    ALPJumpFailedModeOpenDownloadPage = 1,//跳转到下载页
    ALPJumpFailedModeOpenBrowser      = 2,//跳转到浏览器
    ALPJumpFailedModeOpenNone         = 3 //不处理返回错误信息
};

@protocol ALPJumpFailedStrategyDelegate <NSObject>

- (void)failToShowH5WithUrl:(NSString *)url;

@end

@interface ALPJumpFailedStrategy : NSObject

/**
 *  跳转失败处理（可选），不设置默认跳转失败，返回错误信息
 */
@property (nonatomic, assign) ALPJumpFailedMode failedMode;

/**
 *  跳转失败H5页面打开时，自定义webview
 */
@property (nonatomic, strong) UIWebView *webview;

/**
 *  跳转失败，自定义显示webview的代理
 */
@property (nonatomic, weak) id<ALPJumpFailedStrategyDelegate> failToH5Delegate;

@end
