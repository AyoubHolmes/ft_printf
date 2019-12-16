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

int	print(const char *format, va_list *ap)
{
	int		j;
	int		i;
	int		c;
	char	*type;
	format_preciser	flag_indecator = { '\0', 0, 0, 0 };

	i = 0;
	c = 0;
	//if(!Error_handler_function) {
	while (format[i] != '\0')
	{
		if ((j = type_of_arg(&format[i], &i, &flag_indecator, &c)) != -1)
			c += controller(ap, j, &flag_indecator);
		else
		{
			c++;
			write(1, &format[i], 1);
		}
		i++;
	}
	//}
	return (c);
}
