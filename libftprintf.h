/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:38:51 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/11/30 16:38:54 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct 
{
    char	flag;
	int		width;
    int		precision;
	int		star_existence_precision;
    int		star_existence_width;
    int     point_existence;
    int     nbr_spaces;
}   format_preciser;

/*
** ------------------------ Helpers ------------------------------
*/

int		ft_strlen(const char *s);
int		type_of_arg(const char *d, int *i, format_preciser *indicator);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_printf(const char *s, ...);
char	*ft_strdup(const char *s1);
int     ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		is_a_conversion(char d);
int		controller(va_list *ap, int conversion, format_preciser *indicator);
int		print(const char *format, va_list *ap);
int     ft_putchar_fd(char c, int fd);
char	*ft_uitoa(unsigned int nb);
int     help_printer(char c, int i);
int		ft_atoi(const char *str, int *k);
void	initializer(format_preciser *ind, va_list *ap);
void    struct_initializer(format_preciser *ind);

/* 
** ------------------------ Handlers -----------------------------
*/

int		char_handler(va_list *ap, format_preciser *indicator);
int		string_handler(va_list *ap, format_preciser *indicator);
int		int_handler(va_list *ap, format_preciser *indicator);
int		unsigned_int_handler(va_list *ap, format_preciser *indicator);
int     hexa_majuscule_handler(va_list *ap, format_preciser *indicator);
int     hexa_minuscule_handler(va_list *ap, format_preciser *indicator);
int     pointer_handler(va_list *ap, format_preciser *indicator);
int		percentage_handler(va_list *ap, format_preciser *indicator);

/* 
** -------------------------- Printf -----------------------------
*/

int		ft_printf(const char *format, ...);

#endif
