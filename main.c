#include "libftprintf.h"

#define TEST "%-7d\n", -14
int main() {
    int a = ft_printf(TEST);
    int b = printf(TEST);
    printf("%d %d", b, a);
}