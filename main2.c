#include "libftprintf.h"
#include <stdio.h>

int main3()
{
    int x;
    printf("\n%d\n", ft_printf("%08.*d-\n", -5, 3));
    printf("\n%d\n", printf("%08.*d-\n", -5, 3));
    printf("\n%d\n", ft_printf("%0*.*p\n", 0, -6, &x));
    printf("\n%d\n", printf("%0*.*p\n", 0, -6, &x));
    return (0);
}