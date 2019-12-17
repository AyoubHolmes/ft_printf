/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:34:37 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/01 21:34:38 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

//%[flags][width][.precision]specifier

void    width(int *k, format_preciser *ind, const char *d)
{
    int i;

    i = *k;
    while(d[i] != '.' && ft_isdigit(d[i]))
	{
        ind->width =  ind->width * 10 + (d[i] - '0');
        i++;
	}
    if (d[i] == '.')
	    i++;
    *k = i;
}

void    precision(int *k, format_preciser *ind, const char *d)
{
    int i;

    i = *k;
    if(d[i] == '*')
    {
        ind->star_existence = 1;
        i++;
    }
    else
    {
        while (ft_isdigit(d[i]))
	    {
            ind->precision =  ind->precision * 10 + (d[i] - '0');
            i++;
        }
    }
     *k = i;
}

int		type_of_arg(const char *d, int *idx, format_preciser *ind, int *count)
{
    int inter;
    int k;
    int counter_helper;

    inter = *idx;
    counter_helper = *count;
    k = 1;
    if(d[0] == '%')
    {
        while(d[k] == ' ')
        {
            ft_putchar_fd(' ', 1);
            counter_helper++;
            k++;
        }
        if (is_a_flag(d[k], ind))
            k++;
        width(&k, ind, d);
        precision(&k, ind, d);
        inter +=k;
        *idx = inter;
        *count = counter_helper;
    }
    return (is_a_conversion(d[k]));
}
