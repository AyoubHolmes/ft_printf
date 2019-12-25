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
    int extraval;

    extraval = i < 0 ? 1 : 0;
	length = i >= 0 ? ft_strlen(integer) : ft_strlen(integer) + 1;
	param = ind->precision > length ? ind->precision : length;
	if (ind->width > length)
	{
		if (ind->flag == '0' && ind->point_existence == 0)
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			length += help_printer('0', ind->width - param);
		}
        else
        {
            length = help_printer(' ', ind->width - param - extraval);
			length += i < 0 ? ft_putchar_fd('-', 1) : 0;
        }
        
	}
	return (length);
}

int		precision_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int results;

	length = i < 0 ? ft_strlen(integer) + 1 : ft_strlen(integer);
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
			length += precision_handler(ind, integer, i);
			length += width_handler(ind, integer, i);
		}
		else
		{
			length = width_handler(ind, integer, i);
			length += precision_handler(ind, integer);
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
	integer = ft_uitoa(i < 0 ? -i  : i);
	if (ind->width == 0 && ind->precision == 0)
	{
		if (i < 0)
			length = ft_putchar_fd('-', 1);
		length += ft_putstr_fd(integer, 1);
	}
	else
		length = middle_function(ind, integer, i);
	free(integer);
	return (length);
}
