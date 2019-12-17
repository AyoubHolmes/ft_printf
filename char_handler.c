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
	if(ind->flag == '-')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		if (ind->width > 1)
			help_printer(' ', ind->width - 1);
	}
	else
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		if (ind->width > 1)
			help_printer(' ', ind->width - 1);
	}
	return (ind->width);
}
