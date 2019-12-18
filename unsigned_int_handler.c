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

int	unsigned_width_handler(format_preciser *ind, char *integer, int stat)
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

int		unsigned_precision_handler(format_preciser *ind, char *integer, int arg)
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

int		unsigned_intermediaire(format_preciser *ind, char *integer, int arg)
{
	int length;

	if(ind->precision < ind->width && ind->star_existence != 1)
	{
		if (ind->flag == '-')
		{
			ft_putstr_fd(integer, 1);
			length = unsigned_width_handler(ind, integer, 1);
		}
		else
		{
			length = unsigned_width_handler(ind, integer, 2);
			ft_putstr_fd(integer, 1);
		}
	}
	else 
		length = unsigned_precision_handler(ind, integer, arg);
	return (length);
}

int		unsigned_int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int arg;
	unsigned int i;

	if(ind->star_existence == 1)
	{
		arg = va_arg(*ap, int);
	}
	integer = ft_uitoa(i);
	if (ind->precision == 0 && ind->width == 0)
		ft_putstr_fd(integer, 1);
	else
		length = unsigned_intermediaire(ind, integer, arg);
	free(integer);
	return (length);
}


/* int		unsigned_int_handler(va_list *ap, format_preciser *ind)
{
	char *i;

	i = ft_uitoa(va_arg(*ap, int));
	if(ind->flag == '-')
	{
		ft_putstr_fd(i, 1);
	}
	else
	{
		ft_putstr_fd(i, 1);
	}
	return (ft_strlen(i));
}

 */