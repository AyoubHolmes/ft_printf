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
    int test;
} flag;

int		ft_strlen(const char *s);
int		type_of_arg(const char *d, int *i, flag *indicator);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_printf(const char *s, ...);
char	*ft_strdup(const char *s1);
char	*ft_add(const char *s1, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		is_a_flag(char d);
int		is_a_conversion(char d);
int		controller(va_list *ap, int conversion, flag *indicator);
int		print(const char *format, va_list *ap);
void	ft_putchar_fd(char c, int fd);
int		char_handler(va_list *ap, flag *indicator);
int		string_handler(va_list *ap, flag *indicator);
int		int_handler(va_list *ap, flag *indicator);
char	*ft_uitoa(unsigned int nb);
int		unsigned_int_handler(va_list *ap, flag *indicator);
int     hexa_majuscule_handler(va_list *ap, flag *indicator);
int     hexa_minuscule_handler(va_list *ap, flag *indicator);
int     pointer_handler(va_list *ap, flag *indicator);

#endif
