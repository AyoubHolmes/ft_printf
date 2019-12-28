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

void	u_initilizer(format_preciser *ind, va_list *ap)
{
	int j;

	if (ind->star_existence_width == 1)
		ind->width = va_arg(*ap, int);
	if (ind->star_existence_precision == 1)
		ind->precision = va_arg(*ap, int);
}

int	u_width_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int	param;

	length = ft_strlen(integer);
	param = ind->precision > length ? ind->precision : length;
	if (ind->width > length)
	{
		if (ind->flag == '0' && ind->point_existence == 0)
			length = help_printer('0', ind->width - param);
        else
            length = help_printer(' ', ind->width - param);
        
	}
	return (length);
}

int		u_precision_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int results;

	length = ft_strlen(integer);
	results = help_printer('0', ind->precision - length);
	results += ft_putstr_fd(integer, 1);
	return (results);
}

int		u_middle_function(format_preciser *ind, char *integer, int i)
{
	int length;

	if(ind->precision < ind->width)
	{
		if (ind->flag == '-')
		{
			length += u_precision_handler(ind, integer, i);
			length += u_width_handler(ind, integer, i);
		}
		else
		{
			length = u_width_handler(ind, integer, i);
			length += u_precision_handler(ind, integer, i);
		}
	}
	else
		length += u_precision_handler(ind, integer, i);	
	return (length);
}

int		unsigned_int_handler(va_list *ap, format_preciser *ind)
{
	char *integer;
	int length;
	int i;

	length = 0;
	u_initilizer(ind, ap);
	i = va_arg(*ap, int);
	integer = ft_uitoa(i);
	if (ind->width == 0 && ind->precision == 0)
		length += ft_putstr_fd(integer, 1);
	else
		length = u_middle_function(ind, integer, i);
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