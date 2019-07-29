#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define RED                 "\033[0;31m"
#define BOLD_RED            "\033[1;31m"
#define GREEN               "\033[0;32m"
#define BOLD_GREEN          "\033[1;32m"
#define YELLOW              "\033[0;33m"
#define BOLD_YELLOW         "\033[1;33m"
#define BLUE                "\033[0;34m"
#define BOLD_BLUE           "\033[1;34m"
#define MAGENTA             "\033[0;35m"
#define BOLD_MAGENTA        "\033[1;35m"
#define CYAN                "\033[0;36m"
#define BOLD_CYAN           "\033[1;36m"
#define RESET_COLOR         "\033[0m"

typedef enum
{
  Red               ,
  BoldRed           ,
  Green             ,
  BoldGreen         ,
  Yellow            ,
  BoldYellow        ,
  Blue              ,
  BoldBlue          ,
  Magenta           ,
  BoldMagenta       ,
  Cyan              ,
  BoldCyan          ,
  Reset
} color_enum;

#define foreach(item, array) \
    for(int keep = 1, \
        count = 0,\
        size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
          for(item = (array) + count; keep; keep = !keep)

#define LOG(msg, color, tag)\
{\
  switch (color)\
  {\
    case Red:\
      printf(RED);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case BoldRed:\
      printf(BOLD_RED);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case Green:\
      printf(GREEN);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case BoldGreen:\
      printf(BOLD_GREEN);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case Yellow:\
      printf(YELLOW);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case BoldYellow:\
      printf(BOLD_YELLOW);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case Blue:\
      printf(BLUE);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case BoldBlue:\
      printf(BOLD_BLUE);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case Magenta:\
      printf(MAGENTA);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case BoldMagenta:\
      printf(BOLD_MAGENTA);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case Cyan:\
      printf(CYAN);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    case BoldCyan:\
      printf(BOLD_CYAN);\
      printf("[%s]: %s\n", tag, msg);\
      printf(RESET_COLOR);\
      break;\
    default:\
      printf(RESET_COLOR);\
      printf("[%s]: %s\n", tag, msg);\
      break;\
  }\
}

#define TRACE_LOG(fmt, args...)\
{\
  printf(RED);\
  fprintf(stdout, fmt, ##args);\
  printf(RESET_COLOR);\
}\

void test_colors()
{
  LOG("hello there!\n", Red, "Red");
  LOG("hello there!\n", BoldRed, "BoldRed");
  LOG("hello there!\n", Green, "Green");
  LOG("hello there!\n", BoldGreen, "BoldGreen");
  LOG("hello there!\n", Yellow, "Yellow");
  LOG("hello there!\n", BoldYellow, "BoldYellow");
  LOG("hello there!\n", Blue, "Blue");
  LOG("hello there!\n", BoldBlue, "BoldBlue");
  LOG("hello there!\n", Magenta, "Magenta");
  LOG("hello there!\n", BoldMagenta, "BoldMagenta");
  LOG("hello there!\n", Cyan, "Cyan");
  LOG("hello there!\n", BoldCyan, "BoldCyan");
}