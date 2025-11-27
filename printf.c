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


int print_double(va_list *args)
{
    double n = va_arg(*args, double);
    int count = 0;

    /* Handle negative numbers */
    if (n < 0)
    {
        putchar('-');
        count++;
        n = -n;
    }

    /* Extract integer part */
    long int_part = (long)n;

    /* Extract fractional part (6 decimals) */
    double frac = n - int_part;
    long dec_part = (long)(frac * 1000000);

    /* Print integer part */
    long div = 1;
    long tmp = int_part;

    if (tmp == 0)
    {
        putchar('0');
        count++;
    }
    else
    {
        /* Find divisor */
        while (tmp >= 10)
        {
            tmp /= 10;
            div *= 10;
        }

        /* Print each digit */
        while (div > 0)
        {
            putchar((int_part / div) % 10 + '0');
            count++;
            div /= 10;
        }
    }

    /* Print decimal separator */
    putchar('.');
    count++;

    /* Print fractional digits (fixed 6 digits) */
    div = 100000;
    while (div > 0)
    {
        putchar((dec_part / div) % 10 + '0');
        count++;
        div /= 10;
    }

    return count;
}


int print_char(va_list *args)
{
    int count = 0;
    char c = va_arg(*args, int);

    /* Print one character */
    putchar(c);
    return 1;
}

int print_string(va_list *args)
{
    int i = 0;
    char *s = va_arg(*args, char *);

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
    {'d' ,print_double},
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
    va_start(values, format);

    int i = 0;
    int count = 0;

    while (format[i] != '\0')
    {
        /* Direct character printing */
        if (format[i] != '%')
        {
            putchar(format[i]);
            count++;
        }
        else
        {
            /* Match format specifier */
            for (int j = 0; correspondance[j].f != NULL; j++)
            {
                if (format[i + 1] == correspondance[j].c)
                {
                    count += correspondance[j].f(&values);
                }
            }
            i++; /* Skip format specifier char */
        }
        i++;
    }

    return count;
}