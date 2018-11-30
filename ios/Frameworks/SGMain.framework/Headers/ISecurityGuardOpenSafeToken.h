//
//  ISecurityGuardOpenSafeToken.h
//  SecurityGuardMain
//
//  Created by chenkong on 15/12/17.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardOpenSafeToken_h
#define ISecurityGuardOpenSafeToken_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardOpenSafeToken <NSObject, IOpenSecurityGuardPluginInterface>

/**
 *  存储token
 *  @param value 存储的value
 *  @param key token值对应的key
 *  @return 存储操作的结果
 */
- (BOOL) saveToken: (NSString*) value
            forKey: (NSString*) key
        additional: (NSString*) additional
              flag: (int) flag;

/**
 *  检测token是否存在
 *  @param key string值对应的key
 *  @return 检测token是否存在的结果
 */
- (BOOL) isTokenExist: (NSString*) key;

/**
 *  删除本地存储的token
 *  @param key 存储值要使用的key
 *  @return 存储操作结果
 */
- (void) removeToken: (NSString*) key;

/**
 *  使用token加密数据
 *  @param key token值对应的key
 *  @param plaintext 待加密的byte数组
 *  @param flag 扩展参数，缺省为0
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSData*) encryptWithToken: (NSString*) key
                   inputData: (NSData*) plaintext
                        flag: (int)  flag;

/**
 *  使用token解密数据
 *  @param key token值对应的key
 *  @param encrypted 待解密的数据
 *  @param flag 扩展参数，缺省为0
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSData*) decryptWithToken: (NSString*)  key
                   inputData: (NSData*) encrypted
                        flag: (int)  flag;

/**
 *  使用token对数据进行签名
 *  @param key token值对应的key
 *  @param data 待签名的byte数组
 *  @param flag 扩展参数，缺省为0
 *  @return 返回签名结果，签名失败返回nil
 */
- (NSString*) signWithToken: (NSString*) key
                  inputData: (NSData*) data
                       flag: (int) flag;

@end

#endif /* ISecurityGuardOpenSafeToken_h */
