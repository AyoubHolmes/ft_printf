/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:17:52 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/02 22:17:53 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// %[flags][width][.precision]specifier
// flags = -,0, *, minimum field 
// width = integer
// precision = .integer

int is_a_flag(char d, format_preciser *a)
{
	if((d == '-' || d == '0') && !a->flag)
	{
		a->flag = d;
		return(1);
	}
	return (0);
}
