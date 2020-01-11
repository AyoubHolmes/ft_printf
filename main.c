#include "libftprintf.h"
#define TEST "%.*d\n",-10, 0
// #define TEST "%15.p %15.x %15.X %15.u %*.d\n",&main,159, 0,45,5,10

int main(int ac, char *av[]) {
    /* int i,j,k;
    int y,x;
    i = -6;
    while (i < 7)
    {
        j = -6;
        while (j < 7)
        {
            k = -6;
            while (k < 7)
            {
                y = ft_printf("%.*d\n",i,k);
                x = printf("%.*d\n",i,k);
                if (x != y)
                    {
                        printf("\n-----------------F--------------------------\n");
                        printf("\n%d %d \n",i,k);
                        printf("%d %d", x, y);
                        return 0;
                    }
                k++;
            }
            j++;
        }
        i++;
    }
    printf("Great"); */
    int a = ft_printf(TEST);;
    int b = printf(TEST);
    printf("%d-%d\n", b, a);

}