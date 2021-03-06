/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:34:37 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/01 21:34:38 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	helper_width(int *k, t_format_preciser *ind, const char *d)
{
	int i;

	i = *k;
	while (d[*k] == '0' || d[*k] == '-')
	{
		if (d[*k] == '-')
			ind->flag = '-';
		(*k)++;
	}
	if (ind->flag == '\0' && i != *k)
		ind->flag = '0';
}

static void	width(int *k, t_format_preciser *ind, const char *d)
{
	helper_width(k, ind, d);
	if (d[*k] == '*')
	{
		ind->star_existence_width = 1;
		(*k)++;
	}
	else
	{
		if (d[*k] == '0')
			ind->flag = '0';
		ind->width = ft_atoi(&d[*k], k);
		if (ind->width < 0)
		{
			ind->flag = '-';
			ind->width *= -1;
		}
	}
	if (d[*k] == '.')
	{
		ind->point_existence = 1;
		(*k)++;
	}
}

static void	precision(int *k, t_format_preciser *ind, const char *d)
{
	ind->precision = 1;
	while (d[*k] == '0' || d[*k] == '-')
	{
		if (d[*k] == '-')
			ind->precision = -1;
		(*k)++;
	}
	if (d[*k] == '*')
	{
		ind->star_existence_precision = 1;
		(*k)++;
	}
	else
	{
		ind->precision *= ft_atoi(&d[*k], k);
		if (ind->precision < 0)
		{
			ind->width = -1 * ind->precision;
			ind->precision = 0;
			ind->flag = '-';
		}
	}
}

int			type_of_arg(const char *d, int *idx, t_format_preciser *ind)
{
	int k;

	k = 1;
	if (d[0] == '%')
	{
		width(&k, ind, d);
		precision(&k, ind, d);
		*(idx) += k;
		return (is_a_conversion(d[k]));
	}
	return (-1);
}
