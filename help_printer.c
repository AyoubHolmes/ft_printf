/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:42:07 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/15 17:42:09 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    help_printer(char c, int i)
{
	while(i--)
		ft_putchar_fd(c , 1);
}
