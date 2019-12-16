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

	i = ft_itoa(va_arg(*ap, int));
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
