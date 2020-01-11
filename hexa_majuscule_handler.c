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

int		x_width_handler_maj(format_preciser *ind, unsigned int x)
{
	int	param;
	int length;

	length = size_hexa(x);
	param = ind->precision > length ? ind->precision : length;
	if (ind->flag == '0')
	{
		if (ind->point_existence == 0 || (ind->precision < 0 \
			&& ind->star_existence_precision == 1))
			length = help_printer('0', ind->width - param);
		else
			length = help_printer(' ', ind->width - param);
	}
	else
		length = help_printer(' ', ind->width - param);
	return (length);
}

int		x_precision_handler_maj(format_preciser *ind, unsigned int x)
{
	int length;
	int results;

	length = size_hexa(x);
	results = help_printer('0', ind->precision - length);
	if (ind->precision == 0 && ind->point_existence == 1 && x == 0)
	{
		if (ind->width != 0)
			results += ft_putchar_fd(' ', 1);
	}
	else
	{
		hexa_maj(x);
		results += length;
	}
	return (results);
}

int		x_middle_function_maj(format_preciser *ind, unsigned int x)
{
	int length;

	if (ind->width < 0)
	{
		ind->width *= -1;
		ind->flag = '-';
	}
	if (ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = X_precision_handler(ind, x);
			length += X_width_handler(ind, x);
		}
		else
		{
			length = X_width_handler(ind, x);
			length += X_precision_handler(ind, x);
		}
	}
	else
		length = X_precision_handler(ind, x);
	return (length);
}

int		hexa_majuscule_handler(va_list *ap, format_preciser *ind)
{
	int				length;
	unsigned int	x;

	initializer(ind, ap);
	x = va_arg(*ap, unsigned int);
	if (ind->width == 0 && ind->point_existence == 0)
	{
		hexa_maj(x);
		length = size_hexa(x);
	}
	else
		length = X_middle_function(ind, x);
	return (length);
}
