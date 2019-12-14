/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_majuscule_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:49:18 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:49:19 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
	basic version, can be modified later.
*/
static void		to_hexa(unsigned int n)
{
	if(n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd('A' + n - 10, 1);
}

static void		hexa(unsigned int n)
{
	if (n / 16)
		hexa(n / 16);
	to_hexa(n%16);
}

static int		size_hexa(unsigned int n)
{
	int i;

	i = 0;
	while(n !=0)
	{
		i++;
		n /= 16;
	}
	return (i);
} 
int     hexa_majuscule_handler(va_list *ap, flag *indicator)
{
	unsigned int x;

	x = va_arg(*ap, unsigned int);
	/*
		flag traitement
	*/
	hexa(x);
	return (size_hexa(x)/* + flag size */);
}
