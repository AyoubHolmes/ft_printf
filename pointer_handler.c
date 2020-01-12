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

static int		size_hexa_pointer(long long int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while(n !=0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static void		to_hexa(long long int n)
{
	if(n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd('a' + n - 10, 1);
}

static void		hexa(long long int n)
{
	if (n / 16)
		hexa(n / 16);
	to_hexa(n%16);
}

int		Pointer_width_handler(format_preciser *ind, long long int i, int *xdone)
{
	int	param;
	int length;

	length = size_hexa_pointer(i);
	param = ind->precision > length ? ind->precision: length;
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
        length = help_printer(' ', ind->width - param - 2);
	return (length);
}

int		Pointer_precision_handler(format_preciser *ind, long long int i, int xdone)
{
	int results;
	int length;

	length = size_hexa_pointer(i);
	results = xdone == 0 ? ft_putstr_fd("0x", 1) : 0;
	results += help_printer('0', ind->precision - length);
	if (ind->precision == 0 && ind->point_existence == 1 && i == 0)
	{
		if (ind->width != 0)
			results += ft_putchar_fd(' ', 1);
	}
	else
	{
		hexa(i);
		results += length;
	}
	return (results);
}

int		Pointer_middle_function(format_preciser *ind, long long int i)
{
	int length;
	int xdone;

	xdone = 0;
	if (ind->width < 0)
	{
		ind->width *= -1;
		ind->flag = '-';
	}
	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = Pointer_precision_handler(ind, i, xdone);
			length += Pointer_width_handler(ind, i, &xdone);
		}
		else
		{
			length = Pointer_width_handler(ind, i, &xdone);
			length += Pointer_precision_handler(ind, i, xdone);
		}
	}
	else
		length = Pointer_precision_handler(ind, i, xdone);
	return (length);
}

int     pointer_handler(va_list *ap, format_preciser *ind)
{
	long long int x;
	int length;

	initializer(ind, ap);
	x = va_arg(*ap, long long int);
	if (ind->width == 0 && ind->point_existence == 0)
	{
		length = ft_putstr_fd("0x", 1);
		hexa(x);
		length += size_hexa_pointer(x);
	}
	else
		length = Pointer_middle_function(ind, x);
	return (length);
}
