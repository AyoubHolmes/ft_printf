#include "libftprintf.h"

#define TEST "%06.d\n", 54
int main() {
    int a = ft_printf(TEST);
    int b = printf(TEST);
    printf("%d %d", b, a);
}