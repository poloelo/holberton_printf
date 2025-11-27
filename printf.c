#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

flag f_list[] =
{
    {'d' ,print_int},
    {'c', print_char},
    {'i', print_int},
    {'s', print_string},
    {'%' ,print_percent},
    {'0', NULL}
};
/**
 * _printf prints a formatted string.
 * Every '%' introduces a format specifier that is matched
 * with the corresponding function in the lookup table.
 */

int _printf(const char *format, ...)
{
    va_list values;
    int i;
    int count;
    int j, found;

    va_start(values, format);
    count = 0;
    i = 0;

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            count++;
            i++;
        }
        else
        {
            found = 0;
            if (format[i + 1] != '\0')
            {
                for (j = 0; f_list[j].f != NULL; j++)
                {
                    if (format[i + 1] == f_list[j].c)
                    {
                        count += f_list[j].f(&values);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    _putchar('%');
                    _putchar(format[i + 1]);
                    count += 2;
                }
                i += 2; 
            }
            else    /* Case: string ends with '%' */
            {
                va_end(values);
                return -1;  /* IMPORTANT : ne rien afficher */
            }
        }
    }

    va_end(values);
    return count;
}