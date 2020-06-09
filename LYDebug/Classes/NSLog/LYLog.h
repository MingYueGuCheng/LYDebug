//
//  LYLog
//  LYDebug
//
//  Created by 似水灵修 on 16/4/27.
//  Copyright © 2016年 似水灵修. All rights reserved.
//  格式化日志
#ifndef LYLog_h
#define LYLog_h

#ifdef __OBJC__

/** 非DEBUG模式去除NSLog日志  */
#ifdef DEBUG
#define NSLog(format, ...) do { \
    fprintf(stderr, "<%s : %d-Line> %s\n", \
    [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], \
    __LINE__, __func__); \
    (NSLog)((format), ##__VA_ARGS__); \
    fprintf(stderr, "---->˚<----\n"); \
} while (0)
#else
#define NSLog(...) {}
#endif

/** 强制打印日志  */
#define LYLog(format, ...) do { \
    fprintf(stderr, "<%s : %d-Line> %s\n", \
    [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], \
    __LINE__, __func__); \
    (NSLog)((format), ##__VA_ARGS__); \
    fprintf(stderr, "---->˚<----\n"); \
} while (0)

#endif

#endif /* LYLog_h */

