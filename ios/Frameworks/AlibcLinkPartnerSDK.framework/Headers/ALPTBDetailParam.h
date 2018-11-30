//
//  ALPTBDetailParam.h
//  ALPLinkPartnerSDK
//
//  Created by czp on 16/9/22.
//  Copyright © 2016年 czp. All rights reserved.
//

#import "ALPJumpParam.h"

@interface ALPTBDetailParam : ALPJumpParam

/**
 *  itemId,要跳转到的商品
 */
@property (nonatomic, strong) NSString *itemId;

/**
 *  初始化,itemId(必传)
 *
 *  @param itemId itemId
 */
-(instancetype)initWithItemId:(NSString *)itemId;


@end
