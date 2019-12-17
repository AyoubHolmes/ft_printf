/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:16:46 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:16:48 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		string_handler(va_list *ap, format_preciser *ind)
{
	char *s;
	int lenght;

	s = va_arg(*ap, char*);
	lenght = ft_strlen(s);
	if (ind->flag == '-')
	{
		ft_putstr_fd(s, 1);
		if (ind->width > lenght)
			help_printer(' ', ind->width - lenght);
	}
	else
	{
		if (ind->width > lenght)
			help_printer(' ', ind->width - lenght);
		ft_putstr_fd(s, 1);
	}
	lenght = ind->width > lenght ? ind->width : lenght;
	return (lenght);
}
