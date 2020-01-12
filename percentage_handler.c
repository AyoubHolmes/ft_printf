/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:27:26 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/15 17:27:30 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		percentage_handler(va_list *ap, t_format_preciser *ind)
{
	int length;

	initializer(ind, ap);
	if (ind->width != 0)
	{
		if (ind->flag == '-')
		{
			length = ft_putchar_fd('%', 1);
			length += help_printer(' ', ind->width - 1);
		}
		else
		{
			if (ind->flag == '0')
				length = help_printer('0', ind->width - 1);
			else
				length = help_printer(' ', ind->width - 1);
			length += ft_putchar_fd('%', 1);
		}
	}
	else
		length = ft_putchar_fd('%', 1);
	struct_initializer(ind);
	return (length);
}
