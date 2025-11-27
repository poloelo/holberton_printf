#include "main.h"
int print_int(va_list *args)
{
    int n = va_arg(*args, int);
    unsigned int num;
    int divisor = 1;
    unsigned int temp;
    int count = 0;

    /* Handle negative numbers */
    if (n < 0)
    {
        _putchar('-');
        count++;
        num = (unsigned int)(-(n + 1)) + 1;  /* Astuce pour éviter l'overflow */
    }
    else
    {
        num = (unsigned int)n;
    }

    temp = num;

    /* Find divisor */
    while (temp >= 10)
    {
        temp /= 10;
        divisor *= 10;
    }

    /* Print digits */
    while (divisor > 0)
    {
        _putchar((num / divisor) % 10 + '0');
        count++;
        divisor /= 10;
    }

    return count;
}