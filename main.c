#include "libftprintf.h"

#define TEST "%011.5d\n", -5

int main() {
    ft_printf(TEST);
    printf(TEST);
}