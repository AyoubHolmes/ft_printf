#include "libftprintf.h"
#define TEST "%0*.*d\n", 3, -4, 0
// #define TEST "%15.p %15.x %15.X %15.u %*.d\n",&main,159, 0,35,5,3

int main() {
     int i,j,k;
     int y,x;
    i = -2;
    while (i < 3)
    {
        j = -2;
        while (j < 3)
        {
            k = -2;
            while (k < 3)
            {
                y = ft_printf("%0*d\n",i,k);
                x = printf("%0*d\n",i,k);
                printf("\ninputs :%d %d %d\n",i,j, k);
                printf("------------\n");
                if (x != y)
                    {
                        printf("\n----------------- Failed --------------------------\n");
                        printf("\n%d %d %d\n",i,j, k);
                        printf("%d %d", x, y);
                        return 0;
                    }
                k++;
            }
            j++;
        }
        i++;
    }
    printf("Great");
    /* y = ft_printf("%-5.p\n",0);
                x = printf("%-5.p\n", 0);
                printf("\ninputs :%d %d %d\n",5,5, 0);
                printf("------------\n");
    x == y ? printf("Great") : 0; */ 
    /* int a = ft_printf(TEST);;
    int b = printf(TEST); 
    printf("%d-%d\n", b, a);
    int x;
    printf("\n%d\n", ft_printf("%0*.*x\n", 20, -1, &x));
    printf("\n%d\n", printf("%0*.*x\n", 20, -1, &x)); */

}