//
//  TBSDKMTOPEnvConfig.h
//  MtopSDK
//
//  Created by Roger on 11/27/14.
//  Copyright (c) 2014 mtop. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MTOP_REQUEST_SECURITY_CONTROL @"Security_control"

/** TBSDK环境设置 */
typedef enum
{
    environmentDebug =  1,     /**< 枚举，预发环境 */
    environmentDaily,          /**< 枚举，日常环境 */
//    environmentDailyTwo,       /**< 枚举，日常二套环境 */
    environmentRelease         /**< 枚举，正式环境 */
}MtopEnvironment;

@interface TBSDKMTOPEnvConfig : NSObject

@property (nonatomic, strong)            NSString             *appkey;
@property (nonatomic, strong)            NSString             *appSecret;
@property (nonatomic, strong)            NSString             *uid;
@property (atomic)                       BOOL                 isWhiteSecurity;
@property (nonatomic)                    MtopEnvironment      environment;
//@property (strong, nonatomic)            NSString*            gatewayDomain;
//@property (nonatomic, strong)            NSString             *customMtopRequestURL;
@property (nonatomic, strong)            NSString             *authCode;

+ (id)shareInstance;

- (NSString *)appkey;

- (NSString *)readUtdid;

+ (NSString *)urlEncodeString:(NSString *) string;
@end
