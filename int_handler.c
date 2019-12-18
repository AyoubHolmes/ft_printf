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


int	helper(int a, int b, int i)
{
	return (a > b ? a  : b);
}

int	width_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int	param;

	if(ind->star_existence_width != 1)
	{
		length = i >= 0 ? ft_strlen(integer) : ft_strlen(integer) + 1;
		param = helper(ind->precision, length, i);
		if (ind->width > length)
		{

			if (ind->flag == '0')
				length = help_printer('0', ind->width - param);
			else
				length = help_printer(' ', ind->width - param);
		}
	}
	return (length);
}

int		precision_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int results;

	length = ft_strlen(integer);
	results = help_printer('0', ind->precision - length);
	results += ind->precision != 0 ? ft_putstr_fd(integer, 1) :\
				 ft_putchar_fd(' ', 1);
	return (results);
}

int		middle_function(format_preciser *ind, char *integer, int arg_precision, int arg_width, int i)
{
	int length;

	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			length += precision_handler(ind, integer, i);
			length += width_handler(ind, integer, i);
		}
		else
		{
			length = width_handler(ind, integer, i);
			length += i < 0 ? ft_putchar_fd('-', 1) : 0;
			length += precision_handler(ind, integer, i);
		}
	}
	else
	{
		length = i < 0 ? ft_putchar_fd('-', 1) : 0;
		length += precision_handler(ind, integer, i);	
	}
	return (length);
}

int		int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int arg_width;
	int arg_precision;
	int i;

	length = 0;
	if(ind->star_existence_width == 1)
		arg_width = va_arg(*ap, int);
	if(ind->star_existence_precision == 1)
		arg_precision = va_arg(*ap, int);
	integer = ft_itoa((i = va_arg(*ap, int)) < 0 ? -i : i);
	if (ind->precision == 0 && ind->width == 0)
	{
		length = i < 0 ? ft_putchar_fd('-', 1) : 0;
		length += ft_putstr_fd(i == 0 ? "\0" : integer, 1);	
	}
	else
		length = middle_function(ind, integer, arg_precision, arg_width, i);
	free(integer);
	return (length);
}
