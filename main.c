#include "libftprintf.h"
#define TEST "%0*.*d\n", 10, -4, 0
// #define TEST "%15.p %15.x %15.X %15.u %*.d\n",&main,159, 0,75,5,10

int main() {
    int i,j,k;
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
                y = ft_printf("%0*.*u\n",i,j, 123);
                x = printf("%0*.*u\n",i, j , 123);
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
    /* int a = ft_printf(TEST);;
    int b = printf(TEST); 
    printf("%d-%d\n", b, a);
    int x;
    printf("\n%d\n", ft_printf("%0*.*x\n", 20, -1, &x));
    printf("\n%d\n", printf("%0*.*x\n", 20, -1, &x)); */

}