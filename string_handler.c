/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:16:46 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:16:48 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	string_transformer_precision(t_format_preciser *ind, \
		char **s, int *checker)
{
	int length;
	int x;

	*checker = 0;
	if (*s == NULL)
		*s = "(null)";
	x = ft_strlen(*s);
	length = ind->precision > x ? x : ind->precision;
	if (ind->precision < x && ind->point_existence == 1)
	{
		*s = ft_substr(*s, 0, ind->precision);
		*checker = 1;
	}
}

int			string_handler(va_list *ap, t_format_preciser *ind)
{
	char	*s;
	int		lenght;
	int		x;

	initializer(ind, ap);
	s = va_arg(*ap, char*);
	string_transformer_precision(ind, &s, &x);
	lenght = ft_strlen(s);
	if (ind->flag == '-')
	{
		ft_putstr_fd(s, 1);
		if (ind->width > lenght)
			help_printer(' ', ind->width - lenght);
	}
	else
	{
		if (ind->width > lenght)
			help_printer(ind->flag == '0' ? '0' : ' ', ind->width - lenght);
		ft_putstr_fd(s, 1);
	}
	lenght = ind->width > lenght ? ind->width : lenght;
	x == 1 ? free(s) : 0;
	struct_initializer(ind);
	return (lenght);
}
