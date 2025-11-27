#ifndef PRINTF
#define PRINTF
#include <stdarg.h>
#include <stdlib.h>

typedef struct type_flag{
    char c;
    int (*f)(va_list *);
} flag;

int _printf(const char *format,...);
int _putchar(char c);
int print_int (va_list *args);
int print_double(va_list *args);
int print_string(va_list *args);
int print_char(va_list *args);
int print_percent(va_list *args);

#endif