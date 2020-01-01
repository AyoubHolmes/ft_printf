/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_minuscule_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:49:33 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:49:36 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	x_initilizer(format_preciser *ind, va_list *ap)
{
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
		ind->precision = va_arg(*ap, int);
	if(ind->precision < 0)
			ind->precision = 0;
}

static int		size_hexa(unsigned int n)
{
	int i;

	i = 0;
	while(n !=0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static void		to_hexa(unsigned int n)
{
	if(n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd('a' + n - 10, 1);
}

static void		hexa(unsigned int n)
{
	if (n / 16)
		hexa(n / 16);
	to_hexa(n%16);
}

int		x_width_handler(format_preciser *ind, unsigned int i)
{
	int	param;
	int length;

	param = ind->precision > size_hexa(i) ? ind->precision : size_hexa(i);
	if (ind->flag == '0' && ind->point_existence == 0)
		length = help_printer('0', ind->width - param);
	else
        length = help_printer(' ', ind->width - param);
	return (length);
}

int		x_precision_handler(format_preciser *ind, unsigned int i)
{
	int results;
	int length;

	length = size_hexa(i);
	results = help_printer('0', ind->precision - length);
	if (ind->precision == 0 && i == 0)
	{
		if(ind->width != 0)
			results += ft_putchar_fd(' ', 1);
	}
	else
	{
		hexa(i);
		results += length;
	}
	return (results);
}

int		x_middle_function(format_preciser *ind, unsigned int i)
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
			length = x_precision_handler(ind, i);
			length += x_width_handler(ind, i);
		}
		else
		{
			length = x_width_handler(ind, i);
			length += x_precision_handler(ind, i);
		}
	}
	else
		length = x_precision_handler(ind, i);
	return (length);
}

int     hexa_minuscule_handler(va_list *ap, format_preciser *ind)
{
	unsigned int x;
	int length;

	x_initilizer(ind, ap);
	x = va_arg(*ap, unsigned int);
	if (ind->width == 0 && ind->point_existence == 0)
	{
		hexa(x);
		length = size_hexa(x);
	}
	else
		length = x_middle_function(ind, x);
	return (length);
}
