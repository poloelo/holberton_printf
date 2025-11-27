# _printf

A custom implementation of the printf function in C, recreating the basic functionality of the standard library's printf.

## Description

`_printf` is a variadic function that produces formatted output according to a format string. It processes the format string and prints characters to the standard output, replacing format specifiers with their corresponding values from the argument list.


<img width="675" height="900" alt="printf_organigram" src="https://github.com/user-attachments/assets/d7af2baa-4b35-42ca-ad9d-e159ed008015" />


## Function Prototype

```c
int _printf(const char *format, ...);
```

## Supported Format Specifiers

| Specifier | Description | Output |
|-----------|-------------|--------|
| `%c` | Character | Single character |
| `%s` | String | String of characters |
| `%d` | Decimal integer | Signed decimal integer |
| `%i` | Integer | Signed decimal integer |
| `%%` | Percent sign | Literal '%' character |

## Return Value


- On success: Returns the number of characters printed (excluding the null terminator)
- On error: Returns -1 if the format string ends with a '%' character

## Files

- `printf.h` - Header file containing function prototypes
- `_printf.c` - Main implementation file

## Implementation Details

The function uses a lookup table structure to match format specifiers with their corresponding handler functions:

- `print_char()` - Handles `%c` specifier
- `print_string()` - Handles `%s` specifier
- `print_int()` - Handles `%d` and `%i` specifiers
- `print_percent()` - Handles `%%` specifier

## Usage Example

```c
#include "printf.h"

int main(void)
{
    int count;
    
    count = _printf("Hello %s!\n", "World");
    _printf("Character: %c\n", 'A');
    _printf("Number: %d\n", 42);
    _printf("Percentage: 100%%\n");
    
    return (0);
}
```

### Output
```
Hello World!
Character: A
Number: 42
Percentage: 100%
```


## Compilation

Compile the program using gcc with the following flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -Wno-format -std=gnu89 *.c -o printf
```

## Features

- Handles basic format specifiers
- Supports negative numbers
- NULL string handling (prints "(null)")
- Returns character count
- Error handling for incomplete format strings

## Known Limitations

- Does not support all standard printf format specifiers (e.g., %f, %x, %o, %u, %p)
- Does not support field width, precision, or length modifiers
- Does not support flags like '+', '-', ' ', '#', '0'
- **Bug**: Incorrect handling of `INT_MIN` (-2147483648)

## Authors

Project developed by Ndeye Fatou Samb and Paul Gioria.

## License

This project is part of an educational program.
