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

int	width_handler(format_preciser *ind, char *integer, int stat)
{
	int length;

	length = ft_strlen(integer);
	if (stat == 1)
	{
		if (ind->width > length && ind->width > ind->precision)
			help_printer(' ', ind->width - length);

	}
	else
	{
		if (ind->width > length)
		{
			if (ind->flag == '0')
				help_printer('0', ind->width - length);	
			else
				help_printer(' ', ind->width - length);
		}
	}
	length = ind->width > length ? ind->width : length;
	return (length);
}

int		precision_handler(format_preciser *ind, char *integer, int arg)
{
	int length;

	length = ft_strlen(integer);
	if(ind->star_existence != 1)
	{
		help_printer('0', ind->precision - length);
		ft_putstr_fd(integer, 1);
	}
	else
	{
		ind->precision = arg;
		help_printer('0', arg - length);
		ft_putstr_fd(integer, 1);
	}
	length = ind->precision > length ? ind->precision : length;
	return (length);
}

int		intermediaire(format_preciser *ind, char *integer, int arg)
{
	int length;

	if(ind->precision < ind->width && ind->star_existence != 1)
	{
		if (ind->flag == '-')
		{
			ft_putstr_fd(integer, 1);
			length = width_handler(ind, integer, 1);
		}
		else
		{
			length = width_handler(ind, integer, 2);
			ft_putstr_fd(integer, 1);
		}
	}
	else 
		length = precision_handler(ind, integer, arg);
	return (length);
}

int		int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int arg;
	int i;

	if(ind->star_existence == 1)
	{
		arg = va_arg(*ap, int);
	}
	if((i = va_arg(*ap, int)) < 0)
	{
		i *= -1;
		ft_putchar_fd('-', 1);
	}
	integer = ft_itoa(i);
	if (ind->precision == 0 && ind->width == 0)
		ft_putstr_fd(integer, 1);
	else
		length = intermediaire(ind, integer,arg);
	return (length + 1);
}
