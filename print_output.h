#ifndef PRINT_OUTPUT_H
# define PRINT_OUTPUT_H
#include <stdio.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"  //30-37 text colors
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34;1m" //color with bold font
#define MAGENTA "\033[35;1m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BBLACK   "\033[40m" //40-47 background colors
#define BRED     "\033[41m"
#define BGREEN   "\033[42m"
#define BYELLOW  "\033[43m"
#define BBLUE    "\033[44m"
#define BMAGENTA "\033[45m"
#define BCYAN    "\033[46m"
#define BWHITE   "\033[47;30m"
#define REVERSE  "\033[7;1m"

#define DOLLAR YELLOW "$" RESET

void	print_result(char *exp, char *got); //print expected-result and got-result with yellow dollar (emulated cat -e)
void	print_title(char *title);			//print blue bold font text
void	print_tester_name();				//yellow dollar font


#endif
