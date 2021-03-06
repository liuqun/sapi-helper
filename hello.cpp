#include <iostream>
using namespace std;
#include <sapi/tpm20.h>

#include "GenericDataStructure.h"

// 自行定义 PRINT_LOG() 和 PRINT_FAIL() 等日志输出接口(均以宏定义形式实现)
// @note 程序运行时可以修改全局变量 GLOBAL_LOG_LEVEL 切换日志级别(其有效作用域被限制为单个 C/C++ 源文件)

/**
 * 全局日志级别(用于开发调试)
 */
enum {
    DEBUG=4, ///< 仅用于调试, 输出大量内容
    LOG=3, ///< 输出除了调试信息之外的大部分运行日志
    INFO=3, ///< 输出除了调试信息之外的大部分运行日志
    ONLY_WARNINGS_AND_ERRORS=2, ///< 输出警告信息或错误信息
    ONLY_ERRORS=1, ///< 只输出错误信息(不输出警告信息)
    OFF=0 ///< 不打印任何日志信息
};

static int GLOBAL_LOG_LEVEL = DEBUG; ///<

// 以下这组宏定义改编自 [TPM2.0-TSS/test/integration/log.h](https://github.com/01org/TPM2.0-TSS/blob/master/test/integration/log.h)
#include <stdio.h>
#define print_debug(...) \
    if (GLOBAL_LOG_LEVEL >= DEBUG) \
    { \
        printf("%s:%d:%s(): ", \
                __FILE__, \
                __LINE__, \
                __FUNCTION__); \
        printf(__VA_ARGS__); \
        fflush(stdout); \
    }
#define print_log(...) \
    if (GLOBAL_LOG_LEVEL >= LOG) \
    { \
        printf(__VA_ARGS__); \
        fflush(stdout); \
    }
#define print_warning(...) \
        if (GLOBAL_LOG_LEVEL >= ONLY_WARNINGS_AND_ERRORS) \
        { \
            fprintf(stderr, \
                    "%s:%d:%s(): ", \
                    __FILE__, \
                    __LINE__, \
                    __FUNCTION__); \
            fprintf(stderr, \
                    __VA_ARGS__); \
        }
#define print_fail(...) \
    if (GLOBAL_LOG_LEVEL >= ONLY_ERRORS) \
    { \
        fprintf(stderr, \
                "%s:%d:%s(): ", \
                __FILE__, \
                __LINE__, \
                __FUNCTION__); \
        fprintf(stderr, \
                __VA_ARGS__); \
    }
#define PREFER_UPPERCASE_C_MICROS_AS_REPLACEMENT_OF_LOWERCASE
#if defined(PREFER_UPPERCASE_C_MICROS_AS_REPLACEMENT_OF_LOWERCASE)
#define PRINT_DEBUG print_debug
#define PRINT_LOG print_log
#define PRINT_INFO print_log
#define PRINT_WARNING print_warning
#define PRINT_FAIL print_fail
#define PRINT_ERROR print_fail
#endif
/* 上述宏定义可在大多数主流编译器下编译通过(只要编译器支持 __VA_ARGS__ 语法). GCC 编译器相关文档可以查询 http://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html */
/* 源代码风格约定: 1.使用4个空格取代制表符; 2.函数名全小写并用下划线分割; 3.文件名建议采用全小写, 且文件名中不使用下划线, 单词之间以'-'短横线连接 */

int main() {
    Data myData(32);

    cout << myData.getBufferSize() << endl;
    const TPM2B_DATA *p = Unpack(myData);
    return 0;
}
