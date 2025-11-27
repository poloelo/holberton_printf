#include "printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Each function prints the ASCII characters of a specific type
 * extracted from the variadic argument list.
 */


int print_int(va_list *args)
{
    int n = va_arg(*args,int);
    int divisor = 1;
    int temp = n;
    int count = 0;

    /* Handle negative numbers */
    if (n < 0)
    {
        putchar('-');
        count++;
        n = -n;
        temp = n;
    }

    /* Find the highest divisor */
    while (temp >= 10)
    {
        temp /= 10;
        divisor *= 10;
    }

    /* Print digits one by one */
    while (divisor > 0)
    {
        putchar((n / divisor) % 10 + '0');
        count++;
        divisor /= 10;
    }

    return count;
}


int print_char(va_list *args)
{
    char c = va_arg(*args, int);

    /* Print one character */
    putchar(c);
    return 1;
}

int print_string(va_list *args)
{
    int i = 0;
    char *s = va_arg(*args, char *);

    if (s == NULL)
    {
        s = "(null)";
    }

    /* Print characters until null terminator */
    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
    }
    
    return i;
}

int print_percent(va_list *args)
{
    (void)args;
    /* Print '%' literally */
    putchar('%');
    return 1;
}

/**
 * Structure linking a format specifier to its corresponding print function.
 */

struct type_t {
    char c;
    int (*f)(va_list *);
};

/* Lookup table for format specifiers */
struct type_t correspondance[] =
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
            putchar(format[i]);
            count++;
            i++; // Avancer l'index pour un caractère normal
        }
        else // format[i] est '%'
        {
            found = 0;
            if (format[i + 1] != '\0')
            {
                for (j = 0; correspondance[j].f != NULL; j++)
                {
                    if (format[i + 1] == correspondance[j].c)
                    {
                        count += correspondance[j].f(&values);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    putchar('%');
                    putchar(format[i + 1]);
                    count += 2;
                }
                i += 2; // Avancer l'index de 2 (pour '%' et le spécificateur/caractère qui suit)
            }
            else
            {
                i++; // '%' est le dernier caractère, on avance de 1 pour atteindre '\0' et terminer la boucle.
                /* Comportement défini: le '%' seul en fin de chaîne est ignoré. */
            }
        }
    }

    va_end(values);
    return count;
}