/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:15:23 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:15:25 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		char_handler(va_list *ap, format_preciser *ind)
{
	int length;

	initializer(ind, ap);
	length = 0;
	if (ind->flag == '-')
	{
		length = ft_putchar_fd(va_arg(*ap, int), 1);
		if (ind->width > 1)
			length += help_printer(' ', ind->width - 1);
	}
	else
	{
		if (ind->width > 1)
		{
			length = ind->flag == '0' ? help_printer('0', ind->width - 1)\
				: help_printer(' ', ind->width - 1);
		}
		length += ft_putchar_fd(va_arg(*ap, int), 1);
	}
	return (length);
}
