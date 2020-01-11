/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:33:06 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/01/10 18:33:08 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	signe(const char *c, int *i, int *t)
{
	int k;

	k = 0;
	while (c[k] == '-' || c[k] == '0')
	{
		if (c[k] == '-')
		{
			*t *= -1;
			break ;
		}
		k++;
		(*i)++;
	}
	while (c[k] == '-' || c[k] == '0')
	{
		k++;
		(*i)++;
	}
}

int			ft_atoi(const char *str, int *k)
{
	int				i;
	int				t;
	unsigned int	s;

	i = 0;
	s = 0;
	t = 1;
	signe(&str[i], &i, &t);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (s > 2147483647 && t == -1)
			return (0);
		else if (s > 2147483648 && t == 1)
			return (-1);
		else
		{
			s = s * 10 + str[i] - 48;
			i++;
		}
	}
	*k += i;
	return (s * t);
}
