#pragma once


#include <stdio.h>


#ifndef LOG_PRINTFMETHOD
    #define LOG_PRINTFMETHOD printf
#endif


#ifndef LOG_DISABLE
    #define __LOG_PRINTLN(fmt, ...) LOG_PRINTFMETHOD(fmt "\n", ## __VA_ARGS__)
#else
    #define __LOG_PRINTLN(fmt, ...) (0)
#endif

#define __LOG_STRINGIFY2(x) #x
#define __LOG_STRINGIFY(x) __LOG_STRINGIFY2(x)


#define __LOG_COL_RESET "\e[0m"
#define __LOG_COL_BOLD "\e[1m"
#define __LOG_COL_THIN "\e[2m"
#define __LOG_COL_YELLOW "\e[33m"
#define __LOG_COL_RED "\e[31m"

#define __LOG_STR_FILE __LOG_COL_THIN __FILE__ ":" __LOG_STRINGIFY(__LINE__) ":" __LOG_COL_RESET

#define __LOG_STR_INFO __LOG_COL_BOLD "INFO" __LOG_COL_RESET
#define __LOG_STR_WARN __LOG_COL_YELLOW __LOG_COL_BOLD "WARN" __LOG_COL_RESET
#define __LOG_STR_ERROR __LOG_COL_RED __LOG_COL_BOLD "FAIL" __LOG_COL_RESET


#define __LOG(level, ...) __LOG_PRINTLN(level " " __LOG_STR_FILE " " __VA_ARGS__)


#define INFO(...) __LOG(__LOG_STR_INFO, __VA_ARGS__)
#define WARN(...) __LOG(__LOG_STR_WARN, __VA_ARGS__)
#define ERROR(...) __LOG(__LOG_STR_ERROR, __VA_ARGS__)
