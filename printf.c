#include "printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *  Each function displays in characters ASCII the specifical type of 
 * every argument passed in the variadic variables 
 */

int print_int(va_list *args)
{
    int n = va_arg(*args,int);
    int divisor = 1;
    int temp = n;
    int count = 0;

    if (n < 0)
    {
        putchar('-');
        count++;
        n = -n;
        temp = n;
    }

    /* Trouver le plus grand diviseur */
    while (temp >= 10)
    {
        temp /= 10;
        divisor *= 10;
    }

    /* Imprimer chiffre par chiffre */
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

    /* Signe */
    if (n < 0)
    {
        putchar('-');
        count++;
        n = -n;
    }

    /* Partie entière */
    long int_part = (long)n;

    /* Partie décimale */
    double frac = n - int_part;
    long dec_part = (long)(frac * 1000000); /* 6 décimales */

    /* Impression partie entière */
    long div = 1;
    long tmp = int_part;

    if (tmp == 0)
    {
        putchar('0');
        count++;
    }
    else
    {
        while (tmp >= 10)
        {
            tmp /= 10;
            div *= 10;
        }
        while (div > 0)
        {
            putchar((int_part / div) % 10 + '0');
            count++;
            div /= 10;
        }
    }

    /* point */
    putchar('.');
    count++;

    /* Impression partie décimale (exactement 6 chiffres) */
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
    putchar(c);
    count++;
    return count;
}

int print_string(va_list *args)
{
    int i = 0;
    char *s = va_arg(*args, char *);
    while (s[i] != '\0')
    {
        putchar(s[i]);
        i++;
    }
    return i;
}

int print_percent(va_list *args)
{
    putchar('%');
    return 1;
}

/**
 * Creation of the type_t type that stores a char c and a function pointer.
 * 
 * The correspondance board is there to make links between the option scanned in the format string 
 * and the option in the correspondances board.
 */

struct type_t {
    char c;
    int (*f)(va_list *);
};

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
 * _printf functions prints a formatted string where all the options that starts with '%' 
 * can be replaced by the parameters put after the formatted string in order of appearance
 */

int _printf(const char *format, ...)
{
    va_list values;
    va_start(values, format);

    int i = 0;
    int count = 0;

    while (format[i] != '\0')
    {
        if (format[i] != '%')   
        {
        putchar(format[i]);
        count++;
        }
        else if (format[i] == '%')
        {
            for(int j = 0; correspondance[j].f != NULL ; j++)
            {
                if (format[i + 1] == correspondance[j].c)
                {
                    count += correspondance[j].f(&values);
                }
            }
            i++;
        }
        i++;
    }
    return count;
}