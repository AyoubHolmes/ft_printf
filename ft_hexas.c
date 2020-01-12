/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:20:49 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/01/12 00:20:50 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		size_hexa(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	to_hexa_maj(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd('A' + n - 10, 1);
}

void	hexa_maj(unsigned int n)
{
	if (n / 16)
		hexa_maj(n / 16);
	to_hexa_maj(n % 16);
}

void		to_hexa_min(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd('a' + n - 10, 1);
}

void		hexa_min(unsigned int n)
{
	if (n / 16)
		hexa_min(n / 16);
	to_hexa_min(n % 16);
}
