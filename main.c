#include "libftprintf.h"
#define TEST "%c\n", 0
// #define TEST "%15.p %15.x %15.X %15.u %*.d\n",&main,159, 0,45,5,10

int main(int ac, char *av[]) {
    int a = ft_printf(TEST);;
    int b = printf(TEST);
    printf("%d-%d\n", b, a);
}