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

int	width_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int	param;

	length = i > 0 ? ft_strlen(integer) : ft_strlen(integer) + 1;
	param = ind->precision > length ? ind->precision: length;
	if (ind->width > length)
	{
		if (ind->flag == '0')
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			length += help_printer('0', ind->width - param);	
		}
		else
		{
			length = help_printer(' ', ind->width - param);
			length += i < 0 ? ft_putchar_fd('-', 1) : 0;

		}
	}
	return (length);
}

int		precision_handler(format_preciser *ind, char *integer, int arg, int i)
{
	int length;
	int results;

	length = i < 0 ? ft_strlen(integer) + 1 : ft_strlen(integer);
	results = i < 0  && ind->precision > ind->width ? ft_putchar_fd('-', 1) : 0;
	if(ind->star_existence != 1)
	{
		results = help_printer('0', ind->precision - length);
		results += ft_putstr_fd(integer, 1);
	}
	else
	{
		ind->precision = arg;
		results = help_printer('0', arg - length);
		results += ft_putstr_fd(integer, 1);
	}
	return (results);
}

int		intermediaire(format_preciser *ind, char *integer, int arg, int i)
{
	int length;

	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			length += precision_handler(ind, integer, arg, i);
			length += width_handler(ind, integer, i);
		}
		else
		{
			length = width_handler(ind, integer, i);
			length += precision_handler(ind, integer, arg, i);
		}
	}
	else
	{
		length = precision_handler(ind, integer, arg, i);	
	}
	return (length);
}

int		int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int arg;
	int i;

	length = 0;
	arg = 0;
	if(ind->star_existence == 1)
		arg = va_arg(*ap, int);
	i = va_arg(*ap, int);
	integer = ft_itoa(i < 0 ? -i : i);
	if (ind->precision == 0 && ind->width == 0)
	{
		length = i < 0 ? ft_putchar_fd('-', 1) : 0;
		length += ft_putstr_fd(integer, 1);	
	}
	else
		length = intermediaire(ind, integer, arg, i);
	free(integer);
	return (length);
}
