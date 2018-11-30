//
// Created by mo on 2018/8/15.
//

#import <Foundation/Foundation.h>


@interface NautilusStringUtil : NSObject
+ (BOOL) isBlank:(NSString *)string;
+ (NSString *) nilToEmpty:(NSString *) string;
@end