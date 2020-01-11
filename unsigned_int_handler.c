/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:30:25 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:30:27 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	u_width_handler(format_preciser *ind, int length)
{
	int	param;

	param = ind->precision > length ? ind->precision : length;
	length = 0;
	if (ind->flag == '0')
	{
		if (ind->point_existence == 0 || (ind->precision < 0 \
			&& ind->star_existence_precision == 1))
			length += help_printer('0', ind->width - param);
		else
		length = help_printer(' ', ind->width - param);
	}
	else
        length = help_printer(' ', ind->width - param);
	return (length);
}

int		u_precision_handler(format_preciser *ind, char *integer, unsigned int i)
{
	int length;
	int results;

	results = 0;
	length = ft_strlen(integer);
	results += help_printer('0', ind->precision - length);
	if (ind->precision == 0 && ind->point_existence == 1 && i == 0)
	{
		if (ind->width != 0)
			results += ft_putchar_fd(' ', 1);
	}
	else
		results += ft_putstr_fd(integer, 1);
	return (results);
}

int		u_middle_function(format_preciser *ind, char *integer, unsigned int i)
{
	int length;

	if (ind->width < 0)
	{
		ind->width *= -1;
		ind->flag = '-';
	}
	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = u_precision_handler(ind, integer, i);
			length += u_width_handler(ind, ft_strlen(integer));
		}
		else
		{
			length = u_width_handler(ind, ft_strlen(integer));
			length += u_precision_handler(ind, integer, i);
		}
	}
	else
		length = u_precision_handler(ind, integer, i);
	return (length);
}

int		unsigned_int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	unsigned int i;

	initializer(ind, ap);
	i = va_arg(*ap, unsigned int);
	integer = ft_uitoa(i);
	if (ind->width == 0 && ind->point_existence == 0)
		length = ft_putstr_fd(integer, 1);
	else
		length = u_middle_function(ind, integer, i);
	free(integer);
	return (length);
}
