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

//%[flags][width][.precision][length]specifier

int		type_of_arg(const char *d, int *i, flag *indicator)
{
    int j;
    int k;

    j = *i;
    k = 1;
    if(d[0] == '%')
    {
        if(d[1] == '%')
        {
            j += 2;
            *i = j;
            ft_putchar_fd('%', 1);
        }
        else
        {
            while (is_a_flag(d[k]))
                k++;
            j +=k;
            *i = j;
            indicator->test = 1;
            return (is_a_conversion(d[k]));
        }
    }
    return (-1);
}
