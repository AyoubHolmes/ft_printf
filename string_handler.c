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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st;
	unsigned char *sr;

	st = (unsigned char *)s1;
	sr = (unsigned char *)s2;
	while (n--)
	{
		if (*st != *sr)
			return (*st - *sr);
		st++;
		sr++;
	}
	return (0);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if ((!dst && !src))
		return (NULL);
	if (ft_memcmp(dst, src, n) == 0)
		return (dst);
	s = (unsigned char*)src;
	d = dst;
	while (n--)
	{
		*(d++) = *(s++);
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s;

	len = ft_strlen(s1);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_substr(char const *src, unsigned int start, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	if (!src)
		return (NULL);
	if (start > (unsigned int)ft_strlen(src))
		return (ft_strdup(""));
	len = ft_strlen(src + start);
	if (n > len)
		n = len;
	if ((dst = (char *)malloc(sizeof(char) * n + 1)) == NULL)
		return (NULL);
	ft_memcpy(dst, src + start, n);
	dst[n] = '\0';
	return (dst);
}

void	string_transformer_precision(format_preciser *ind, char **s, int *checker)
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

int		string_handler(va_list *ap, format_preciser *ind)
{
	char *s;
	int lenght;
	int x;

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
