⸻

✅ README.md

# _printf

A custom implementation of the standard C `printf` function.  
This project recreates a simplified version of `printf`, handling several format specifiers and printing output to the standard output stream.

This implementation follows the Holberton School specifications and the ISO C90 (GNU89) standard.

---

## 📌 Features

The `_printf` function supports the following format specifiers:

| Specifier | Output Type             |
|----------|--------------------------|
| `%c`     | Print a single character |
| `%s`     | Print a string           |
| `%d`     | Print a signed integer   |
| `%i`     | Print a signed integer   |
| `%%`     | Print a literal `%`      |

Invalid format specifiers are printed literally (e.g. `"%k"` → `%k`).

If a trailing `%` is found at the end of the string (e.g. `printf("%")`),  
the function returns `-1` and prints nothing — matching project requirements.

---

## 📁 Project Structure

.
├── printf.c       # Main implementation of _printf and handlers
├── printf.h       # Function prototypes and structure definitions
├── man_3_printf   # Manual page for _printf
└── README.md

---

## ⚙️ Compilation

Compile using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c


⸻

🔧 Usage

#include "printf.h"

int main(void)
{
    _printf("Hello %s!\n", "world");         /* → Hello world! */
    _printf("Number: %d\n", 42);             /* → Number: 42 */
    _printf("Character: %c\n", 'A');         /* → Character: A */
    _printf("Percent: %%\n");                /* → Percent: % */

    return 0;
}


⸻

🔍 Return Value

_printf returns:
	•	the total number of characters printed,
	•	-1 if an error occurs (e.g. lone % at the end of the format string).

⸻

🚨 Edge Cases Handled
	•	NULL string → prints (null)
	•	unknown specifier → prints % then the character
	•	% alone at the end → error (-1)
	•	INT_MIN is correctly handled without overflow

⸻

✨ Authors

Project completed as part of the Holberton School Low-Level Programming curriculum.

Your Name / GitHub Username


⸻

📝 License

This project is released under the MIT License.
