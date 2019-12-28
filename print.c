/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:46:36 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/03 19:46:43 by aboulbaz         ###   ########.fr       */
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
}

int	print(const char *format, va_list *ap)
{
	int		j;
	int		i;
	int		c;
	char	*type;
	format_preciser	flag_indecator;

	i = 0;
	c = 0;
	struct_initializer(&flag_indecator);
	while (format[i] != '\0')
	{
		if ((j = type_of_arg(&format[i], &i, &flag_indecator, &c)) != -1)
			c += controller(ap, j, &flag_indecator);
		else
		{
			c += ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	return (c);
}
