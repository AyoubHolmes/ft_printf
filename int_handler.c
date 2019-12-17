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

int		int_handler(va_list *ap, format_preciser *ind)
{
	char *i;
	int lenght;

	i = ft_itoa(va_arg(*ap, int));
	lenght = ft_strlen(i);
	if (ind->flag == '-')
	{
		ft_putstr_fd(i, 1);
		if (ind->width > lenght)
			help_printer(' ', ind->width - lenght);	
	}
	else
	{
		if (ind->width > lenght)
		{
			if (ind->flag == 0)
				help_printer('0', ind->width - lenght);	
			else
				help_printer(' ', ind->width - lenght);
		}
		ft_putstr_fd(i, 1);
	}
	return (ft_strlen(i));
}
