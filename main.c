#include "libftprintf.h"

#define TEST "%04d\n", -4825

int main(int ac, char *av[]) {
    int a = ft_printf(TEST);
    int b = printf(TEST);
    printf("%d %d", b, a);
}