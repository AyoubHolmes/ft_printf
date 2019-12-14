/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:30:25 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:30:27 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		unsigned_int_handler(va_list *ap, flag *indicator)
{
	char *i;

	i = ft_uitoa(va_arg(*ap, int));
	ft_putstr_fd(i, 1);
	return (ft_strlen(i));
}

