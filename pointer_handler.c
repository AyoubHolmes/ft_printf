/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:50:12 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:50:13 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pointer_width_handler(t_format_preciser *ind, \
				long long int i, int *xdone)
{
	int	param;
	int length;

	length = size_hexa_pointer(i);
	param = ind->precision > length ? ind->precision : length;
	if (ind->flag == '0')
	{
		if (ind->point_existence == 0 || (ind->precision < 0 \
			&& ind->star_existence_precision == 1))
		{
			*xdone = 1;
			length = ft_putstr_fd("0x", 1);
			length += help_printer('0', ind->width - param - 2);
		}
		else
			length = help_printer(' ', ind->width - param);
	}
	else
		length = help_printer(' ', ind->width - param - \
		(ind->precision != 0 || ind->point_existence != 1 || i != 0 ? 2 : 1));
	return (length);
}

static int	pointer_precision_handler(t_format_preciser *ind, \
				long long int i, int xdone)
{
	int results;
	int length;

	length = size_hexa_pointer(i);
	results = xdone == 0 ? ft_putstr_fd("0x", 1) : 0;
	results += help_printer('0', ind->precision - length);
	if (ind->precision != 0 || ind->point_existence != 1 || i != 0)
	{
		hexa_pointer(i);
		results += length;
	}
	return (results);
}

static int	pointer_middle_function(t_format_preciser *ind, long long int i)
{
	int length;
	int xdone;

	xdone = 0;
	if (ind->width < 0)
	{
		ind->width *= -1;
		ind->flag = '-';
	}
	if (ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = pointer_precision_handler(ind, i, xdone);
			length += pointer_width_handler(ind, i, &xdone);
		}
		else
		{
			length = pointer_width_handler(ind, i, &xdone);
			length += pointer_precision_handler(ind, i, xdone);
		}
	}
	else
		length = pointer_precision_handler(ind, i, xdone);
	return (length);
}

int			pointer_handler(va_list *ap, t_format_preciser *ind)
{
	long long int	x;
	int				length;

	initializer(ind, ap);
	x = va_arg(*ap, long long int);
	if (ind->width == 0 && ind->point_existence == 0)
	{
		length = ft_putstr_fd("0x", 1);
		hexa_pointer(x);
		length += size_hexa_pointer(x);
	}
	else
		length = pointer_middle_function(ind, x);
	struct_initializer(ind);
	return (length);
}
