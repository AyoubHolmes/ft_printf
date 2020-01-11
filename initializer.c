/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 23:36:58 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/01/10 23:37:00 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initializer(format_preciser *ind, va_list *ap)
{
	if (ind->star_existence_width == 1)
	{
		ind->width = va_arg(*ap, int);
		if (ind->width < 0)
		{
			ind->flag = '-';
			ind->width *= -1;
		}
	}
	if (ind->star_existence_precision == 1)
		ind->precision *= va_arg(*ap, int);
}
