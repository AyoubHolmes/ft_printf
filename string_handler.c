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

	s = va_arg(*ap, char*);
	if (ind->flag == '-')
	{
		ft_putstr_fd(s, 1);
	}
	else
	{
		ft_putstr_fd(s, 1);
	}
	return (ft_strlen(s));
}
