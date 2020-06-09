//
//  NSObject+Code.h
//  LYLog
//
//  Created by 似水灵修 on 2018/9/18.
//

@import Foundation;
@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Code)
/// 代码执行时长，单位：秒
/// @param block callblack
+ (CGFloat)codeTimeBlock:(void (^)(void))block;

@end

NS_ASSUME_NONNULL_END
