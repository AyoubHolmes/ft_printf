/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:51:07 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/01/12 13:51:09 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
