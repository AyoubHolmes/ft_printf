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

void	i_initilizer(format_preciser *ind, va_list *ap)
{
	int j;

	if (ind->star_existence_width == 1)
	{
		ind->width = va_arg(*ap, int);
		if(ind->width < 0)
		{
			ind->flag = '-';
			ind->width *= -1;
		}
	}
	if (ind->star_existence_precision == 1)
	{
		ind->precision = va_arg(*ap, int);
		if (ind->precision < 0)
			ind->precision = 0;
	}
}

int	i_width_handler(format_preciser *ind, char *integer, int i, int length, int *minus_done)
{
	int	param;
	int extraval;

	param = ind->precision > length ? ind->precision : length;
	length = 0;
	extraval = i < 0 ? 1 : 0;
	if (ind->flag == '0' && ind->point_existence == 0)
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			*minus_done = i < 0 ? 1 : 0; 
			length += help_printer('0', ind->width - param -extraval);
		}
		else
            length = help_printer(' ', ind->width - param - extraval);
	return (length);
}

int		i_precision_handler(format_preciser *ind, char *integer, int i, int minus_done)
{
	int length;
	int results;

	results = 0;
	length = ft_strlen(integer);
	if (minus_done == 0 && i < 0)
		results += ft_putchar_fd('-', 1);
	results += help_printer('0', ind->precision - length);
	results += ft_putstr_fd(integer, 1);
	return (results);
}

int		i_middle_function(format_preciser *ind, char *integer, int i)
{
	int length;
	int minus_done;

	minus_done = 0;
	if (ind->width < 0)
	{
		ind->width *= -1;
		ind->flag = '-';
	}
	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = i_precision_handler(ind, integer, i, minus_done);
			length += i_width_handler(ind, integer, i, ft_strlen(integer), &minus_done);
		}
		else
		{
			length = i_width_handler(ind, integer, i, ft_strlen(integer), &minus_done);
			length += i_precision_handler(ind, integer, i, minus_done);
		}
	}
	else
		length = i_precision_handler(ind, integer, i, minus_done);
	return (length);
}

int		int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int i;

	length = 0;
	i_initilizer(ind, ap);
	if(ind->precision < 0)
	{
		ind->width = ind->precision;
		ind->flag = '-';
		ind->precision = 0;
	}
	i = va_arg(*ap, int);
	integer = ft_uitoa(i <= 0 ? -i  : i);
	if (ind->width == 0 && ind->precision == 0 && ind->point_existence == 0)
	{
		if (i < 0)
			length = ft_putchar_fd('-', 1);
		length += ft_putstr_fd(integer, 1);
	}
	else
		length = i_middle_function(ind, integer, i);
	free(integer);
	return (length);
}
