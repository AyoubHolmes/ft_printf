/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 22:07:43 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/09 22:07:47 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	controller(va_list *ap, int conversion)
{
	if (conversion == 1)
		return (int_handler(ap));
	if (conversion == 2)
		return (unsigned_int_handler(ap));
	if (conversion == 3)
		return (char_handler(ap));
	if (conversion == 4)
		return (string_handler(ap));
	if (conversion == 5)
		return (hexa_minuscule_handler(ap));
	if (conversion == 6)
		return (hexa_majuscule_handler(ap));
	if (conversion == 7)
		return (pointer_handler(ap));
	return (0);
}
