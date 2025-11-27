#include "main.h"

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
        _putchar(s[i]);
        i++;
    }
    
    return i;
}