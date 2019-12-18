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

typedef struct 
{
    char	flag;
	int		width;
    int		precision;
	int		star_existence;
}   format_preciser;

/*
** ------------------------ Helpers ------------------------------
*/

int		ft_strlen(const char *s);
int		type_of_arg(const char *d, int *i, format_preciser *indicator, int *counter);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_printf(const char *s, ...);
char	*ft_strdup(const char *s1);
int     ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		is_a_flag(char d, format_preciser *a);
int		is_a_conversion(char d);
int		controller(va_list *ap, int conversion, format_preciser *indicator);
int		print(const char *format, va_list *ap);
int     ft_putchar_fd(char c, int fd);
char	*ft_uitoa(unsigned int nb);
int     help_printer(char c, int i);

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
int		percentage_handler(format_preciser *indicator);

/* 
** -------------------------- Printf -----------------------------
*/
int		ft_printf(const char *format, ...);

#endif
