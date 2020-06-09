//
//  NSObject+Code.m
//  LYLog
//
//  Created by 似水灵修 on 2018/9/18.
//

#import "NSObject+Code.h"
#import <mach/mach_time.h>
#import "LYLog.h"

#ifdef DEBUG
extern uint64_t dispatch_benchmark(size_t count, void (^block)(void));
#endif

@implementation NSObject (Code)

// 代码平均执行时长
+ (CGFloat)codeTimeBlock:(void (^)(void))block {
#ifdef DEBUG
    uint64_t t = dispatch_benchmark(10, block);
    CGFloat time = (CGFloat)t / NSEC_PER_SEC;
#else
    mach_timebase_info_data_t info;
    if (mach_timebase_info(&info) != KERN_SUCCESS) return -1.0;
    
    uint64_t start = mach_absolute_time ();//纳秒级的精确度
    block ();
    uint64_t end = mach_absolute_time ();
    uint64_t elapsed = end - start;
    
    uint64_t nanos = elapsed * info.numer / info.denom;
    CGFloat time = (CGFloat)nanos / NSEC_PER_SEC;
#endif
    NSLog(@"This code runtime：%lf(s)", time);
    return time;
}

@end
