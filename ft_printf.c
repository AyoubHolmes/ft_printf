/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 23:27:26 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/11/30 23:27:28 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	va_start(ap, format);
	counter = print(format, &ap);
	va_end(ap);
	return (counter);
}


int		main(int c, char **arg)
{
	/* ft_printf("%%   sefrgrt % s bfejrbgejbrtwjgbrt\\\\", "ma man");
	ft_printf("%d", ft_printf("\n%d %s %c \n", 78, "wdwdw", 'c'));
	printf("%d", printf("\n%d %s %c \n", 78, "wdwdw", 'c')); 
	unsigned int i = 596321478;
	char *s= "Hello %% \' ehhhhh\n\tok\n";
	unsigned int *p = &i; 
	ft_printf("%s\n",s);*/
	//ft_printf("%d\n",ft_printf("%5d\n", 12));	
	ft_printf("%d\n",ft_printf("%-1d\n", 12));	
	//printf("%d\n",printf("%5d\n", 12));	
	printf("%d\n",printf("%-1d\n", 12));	
	return (0);
}
// printf("flags: %c\twidth: %d\tprecision: %d", ind->flag, ind->width, ind->precision);