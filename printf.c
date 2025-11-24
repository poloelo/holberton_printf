#include "printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void print_int (va_list args);

struct type_t {
    char c;
    void (*f)(va_list);
};

struct type_t correspondance[] = 
{
    {'i', print_int},
    {'0', NULL}
};

int _printf(const char *format, ...)
{
    va_list values;
    va_start(values, format);

    int i = 0;
    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
        putchar(format[i]);
        }
        else if (format[i] == '%')
        {
            for(int j = 0; correspondance[j].f != NULL ; j++)
            {
                if (format[i + 1] == correspondance[j].c)
                {
                    correspondance[j].f(values);
                }
            }
            i++;
        }
        i++;
    }
    return i;
}

void print_int (va_list args)
{
     printf("%i", va_arg(args, int));
}