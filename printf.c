#include "printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Creation of the type_t type that stores a char c and a function pointer.
 * 
 * The correspondance board is there to make links between the option scanned in the format string 
 * and the option in the correspondances board.
 */

struct type_t {
    char c;
    void (*f)(va_list);
};

struct type_t correspondance[] = 
{
    {'i', print_int},
    {'d' ,print_double},
    {'c', print_char},
    {'s', print_string},
    {'%' , print_diese},
    {'0', NULL}
};

/** 
 * _printf functions prints a formatted string where all the options that starts with '%' 
 * can be replaced by the parameters put after the formatted string in order of appearance
 */

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
    return 0;
}

void print_int (va_list args)
{
     printf("%i", va_arg(args, int));
}

void print_double(va_list args)
{
    return;
}

void print_char(va_list args)
{
    return;
}

void print_string(va_list args)
{
    return;
}

void print_diese(va_list args)
{
    putchar('%');
    return;
}