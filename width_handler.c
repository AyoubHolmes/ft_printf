/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:20:22 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/19 04:20:26 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	width_handler(format_preciser *ind, char *integer, int i)
{
	int length;
	int	param;

	length = i >= 0 ? ft_strlen(integer) : ft_strlen(integer) + 1;
	param = ind->precision > length ? ind->precision : length;
	if (ind->width > length)
	{
		if (ind->flag == '0' && ind->precision == 0)
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
