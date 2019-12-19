/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 01:07:55 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/19 01:07:56 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initilizer(format_preciser *ind, va_list *ap)
{
	int j;

	if (ind->star_existence_width == 1)
		ind->width = va_arg(*ap, int);
	if (ind->star_existence_precision == 1)
		ind->precision = va_arg(*ap, int);
}
