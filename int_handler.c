/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:18:14 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:18:16 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		precision_handler(format_preciser *ind, char *integer)
{
	int length;
	int results;

	length = ft_strlen(integer);
	results = help_printer('0', ind->precision - length);
	if (integer[0] == '0')
	{
		if (ind->precision == 0)
			results += ft_putchar_fd(' ', 1);
		else
			results += ft_putchar_fd(0, 1);
	}
	else
		results += ft_putstr_fd(integer, 1);
	return (results);
}

int		middle_function(format_preciser *ind, char *integer, int i)
{
	int length;

	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			length += precision_handler(ind, integer);
			length += width_handler(ind, integer, i);
		}
		else
		{
			length = width_handler(ind, integer, i);
			length += precision_handler(ind, integer);
		}
	}
	else
	{
		length = i < 0 ? ft_putchar_fd('-', 1) : 0;
		length += precision_handler(ind, integer);	
	}
	return (length);
}

int		int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int i;

	length = 0;
	initilizer(ind, ap);
	i = va_arg(*ap, int);
	if (i != INT_MIN)
		integer = ft_itoa(i < 0 ? -i : i);
	else
		integer = ft_uitoa(INT_MIN);
	if (ind->width == 0 && ind->precision == 0)
	{
		if (i < 0)
			length = ft_putchar_fd('-', 1);
		else if(i > 0)
			length += ft_putstr_fd(integer, 1);
	}
	else
		length = middle_function(ind, integer, i);
	free(integer);
	return (length);
}
