/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 00:36:46 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/01/11 00:37:26 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void struct_initializer(format_preciser *ind)
{
	ind->flag = '\0';
	ind->precision = 0;
	ind->width = 0;
	ind->star_existence_precision = 0;
	ind->star_existence_width = 0;
	ind->point_existence = 0;
	ind->nbr_spaces = 0;
}
