/*
 * NSURL+ALIURL.h 
 *
 * 阿里百川电商
 * 项目名称：阿里巴巴电商 AlibcTradeCommon 
 * 版本号：3.1.1.200
 * 发布时间：2017-08-21
 * 开发团队：阿里巴巴百川商业化团队
 * 阿里巴巴电商SDK答疑群号：1488705339  2071154343(阿里旺旺)
 * Copyright (c) 2016-2019 阿里巴巴-移动事业群-百川. All rights reserved.
 */

#ifndef NSURL_ALIURL_h
#define NSURL_ALIURL_h



#import <Foundation/Foundation.h>

@interface NSURL (ALIURL)

/*
 * 判断是否相同url，会比较host，path，query 以及hash参数
 */
- (BOOL)alibc_isSameUrl:(NSURL *)url;

@end

#endif /* NSURL_ALIURL_h */
