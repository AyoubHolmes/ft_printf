/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_an_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:27:34 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/02 22:27:36 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_a_conversion(char d)
{
	if(d == 'd' || d == 'i')
		return (1);
	if(d == 'u')
		return (2);
	if(d == 'c')
		return (3);
	if(d == 's')
		return (4);
	if(d == 'x')
		return (5);
	if(d == 'X')
		return (6);
	if(d == 'p')
		return (7);
	return (-1);
}
