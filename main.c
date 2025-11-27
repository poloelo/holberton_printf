#include "main.h"

int main()
{
    int every_letters = _printf("Ceci est un string : %s\nCeci est un char %c\nCeci est un nombre entier : %i\nCeci est un nombre float : %d\n","Paul Gioria",'P', 22, 22.56);
    _printf("%i", every_letters);
}