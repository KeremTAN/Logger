#include <stdio.h>

#define ANSI_COLOR_RED     "\033[1m\x1b[31m"
#define ANSI_COLOR_GREEN   "\033[1m\x1b[32m"
#define ANSI_COLOR_YELLOW  "\033[1m\x1b[33m"
#define ANSI_COLOR_BLUE    "\033[1m\x1b[34m"
#define ANSI_COLOR_MAGENTA "\033[1m\x1b[35m"
#define ANSI_COLOR_CYAN    "\033[1m\x1b[36m"
#define ANSI_COLOR_WHITE   "\033[1m\x1b[37m"
#define ANSI_COLOR_RESET   "\033[1m\x1b[0m"

#define LOG_RED(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_RED,X,ANSI_COLOR_RESET,Y)
#define LOG_GREEN(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_GREEN,X,ANSI_COLOR_RESET,Y)
#define LOG_YELLOW(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_YELLOW,X,ANSI_COLOR_RESET,Y)
#define LOG_BLUE(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_BLUE,X,ANSI_COLOR_RESET,Y)
#define LOG_MAGENTA(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_MAGENTA,X,ANSI_COLOR_RESET,Y)
#define LOG_CYAN(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_CYAN,X,ANSI_COLOR_RESET,Y)
#define LOG_WHITE(X,Y) printf("%s%s %s%s\n",ANSI_COLOR_WHITE,X,ANSI_COLOR_RESET,Y)