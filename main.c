#include "libftprintf.h"

/* #define TEST1 "this % d number\n", -267
#define TEST2 "% d\n", -1
#define TEST3 "% 7d\n", 33
#define TEST4 "% 7d\n", -14
#define TEST5 "% 3d\n", 0
#define TEST6 "% 5d\n", -2562
#define TEST7 "% 4d\n", -2464
#define TEST8 "% -7d", 33
#define TEST9 "% -7d", -14
#define TEST10 "% -3d", 0
#define TEST11 "% -5d", -2562
#define TEST12 "% -4d", -2464
#define TEST13 "% .6d", -3
#define TEST14 "% .4d", -2372
#define TEST15 "% .3d",-23646
#define TEST16 "% 05d", 43
#define TEST17 "% 07d", -54
#define TEST18 "% 03d", 0
#define TEST19 "% 04d", -532
#define TEST20 "% 04d", -4825
#define TEST21 "% 8.5d", 34
#define TEST22 "% 10.5d", -216
#define TEST23 "% 8.5d", 0
#define TEST24 "% 3.3d", -8462
#define TEST25 "% -8.5d", 34
#define TEST26 "% -10.5d", -216
#define TEST27 "% -8.5d", 0
#define TEST28 "% -8.3d", 8375 */
#define TEST "%d\n", 0

int main(int ac, char *av[]) {
    int a = ft_printf(TEST);
    int b = printf(TEST);
    printf("%d-%d", b, a);
}