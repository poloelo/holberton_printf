#ifndef PRINTF
#define PRINTF
#include <stdarg.h>
#include <stdlib.h>

struct type_t {
    char c;
    void (*f)(va_list);
};

int _printf(const char *format,...);
void print_int (va_list args);

#endif