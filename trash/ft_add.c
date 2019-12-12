/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:48:39 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/01 22:48:40 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_add(const char *s1, char c)
{
	int		len;
	int		i;
	char	*s;

	len = ft_strlen(s1);
	if (!(s = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = '\0';
	return (s);
}
