/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:26:00 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:26:02 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		size_unsigned_int(unsigned int n)
{
	int				i;
	unsigned int	temp;

	temp = n;
	i = 0;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	return (n == 0 ? 1 : i);
}

char					*ft_uitoa(unsigned int nb)
{
	int		i;
	char	*nbr;

	i = size_unsigned_int(nb);
	if (!(nbr = (char*)malloc(i + 1)))
		return (0);
	nbr[i] = 0;
	if (nb == 0)
		nbr[0] = '0';
	while (nb != 0)
	{
		i--;
		nbr[i] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (nbr);
}
