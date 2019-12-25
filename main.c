#include "libftprintf.h"

#define TEST "%5.3d\n",-1111

int main() {
    int a = ft_printf(TEST);
    int b = printf(TEST);
    printf("%d %d", a, b);
}