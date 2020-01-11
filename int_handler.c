/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:18:14 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/01/11 02:24:22 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	i_width_handler(format_preciser *ind, int i, int length, \
		int *minus_done)
{
	int	param;
	int extraval;

	param = ind->precision > length ? ind->precision : length;
	length = 0;
	extraval = i < 0 ? 1 : 0;
	if (ind->flag == '0')
	{
		if (ind->point_existence == 0 || (ind->precision < 0 \
			&& ind->star_existence_precision == 1))
		{
			length = i < 0 ? ft_putchar_fd('-', 1) : 0;
			*minus_done = i < 0 ? 1 : 0;
			length += help_printer('0', ind->width - param - extraval);
		}
		else
			length = help_printer(' ', ind->width - param - extraval);
	}
	else
		length = help_printer(' ', ind->width - param - extraval);
	return (length);
}

static int	i_precision_handler(format_preciser *ind, char *integer, int i, \
		int minus_done)
{
	int length;
	int results;

	results = 0;
	length = ft_strlen(integer);
	if (minus_done == 0 && i < 0)
		results = ft_putchar_fd('-', 1);
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

static int	i_middle_function(format_preciser *ind, char *integer, int i)
{
	int length;
	int minus_done;

	minus_done = 0;
	if (ind->width < 0)
	{
		ind->width *= -1;
		ind->flag = '-';
	}
	if (ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length = i_precision_handler(ind, integer, i, minus_done);
			length += i_width_handler(ind, i, ft_strlen(integer), &minus_done);
		}
		else
		{
			length = i_width_handler(ind, i, ft_strlen(integer), &minus_done);
			length += i_precision_handler(ind, integer, i, minus_done);
		}
	}
	else
		length = i_precision_handler(ind, integer, i, minus_done);
	return (length);
}

int			int_handler(va_list *ap, format_preciser *ind)
{
	char	*integer;
	int		length;
	int		i;

	initializer(ind, ap);
	i = va_arg(*ap, int);
	length = 0;
	integer = ft_uitoa(i <= 0 ? -i : i);
	if (ind->width == 0 && ind->precision == 0 && ind->point_existence == 0)
	{
		if (i < 0)
			length += ft_putchar_fd('-', 1);
		length += ft_putstr_fd(integer, 1);
	}
	else
		length += i_middle_function(ind, integer, i);
	free(integer);
	return (length);
}
