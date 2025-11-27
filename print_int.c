#include "main.h"


int print_int(va_list *args)
{
    int n = va_arg(*args, int);
    int divisor = 1;
    int temp, count = 0;

    /* Special case: INT_MIN */
    if (n == -2147483648)
    {
        _putchar('-');
        _putchar('2');
        count += 2;
        n = 147483648; /* Remove the leading "2" */
    }

    /* Handle negative numbers */
    if (n < 0)
    {
        _putchar('-');
        count++;
        n = -n;
    }

    temp = n;

    /* Find divisor */
    while (temp >= 10)
    {
        temp /= 10;
        divisor *= 10;
    }

    /* Print digits */
    while (divisor > 0)
    {
        _putchar((n / divisor) % 10 + '0');
        count++;
        divisor /= 10;
    }

    return count;
}

