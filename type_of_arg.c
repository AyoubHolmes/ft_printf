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
//%[flags][width][.precision]specifier

void    width(int *k, format_preciser *ind, const char *d)
{
    if(d[*k] == '*')
    {
        ind->star_existence_width = 1;
        (*k)++;
    }
    else
    {
        if (d[*k] == '-')
            (*k)++;
        while(d[*k] != '.' && ft_isdigit(d[*k]))
	    {
            ind->width =  ind->width * 10 + (d[*k] - '0');
            (*k)++;
	    }
    }
    if (d[*k] == '.')
    {
        ind->point_existence = 1;
        (*k)++;
    }
}

void    precision(int *k, format_preciser *ind, const char *d)
{
    int j;

    j = 1;
    if(d[*k] == '*')
    {
        ind->star_existence_precision = 1;
        (*k)++;
    }
    else
    {
        if(d[*k] == '-')
        {
            j = -1;
            (*k)++;
        }
        while (ft_isdigit(d[*k]))
	    {
            ind->precision =  ind->precision * 10 + (d[*k] - '0');
            (*k)++;
        }
        ind->precision *= j;
    }
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
        if (is_a_flag(d[k], ind))
            k++;
        width(&k, ind, d);
        precision(&k, ind, d);
        inter +=k;
        *idx = inter;
        *count = counter_helper;
        return (is_a_conversion(d[k]));
    }
    return (-1);
}
