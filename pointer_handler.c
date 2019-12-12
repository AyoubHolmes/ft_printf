/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:50:12 by aboulbaz          #+#    #+#             */
/*   Updated: 2019/12/11 18:50:13 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		to_hexa(int n)
{
	if(n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd('a' + n - 10, 1);
}
static void		pointer(long long int n)
{
	if (n / 16)
		pointer(n / 16);
	pointer(n%16);
}

static int		size_pointer(long long int n)
{
	int i;

	i = 0;
	while(n !=0)
	{
		i++;
		n /= 16;
	}
	return (i);
} 
int     pointer_handler(va_list *ap)
{
	long long int x;

	x = va_arg(*ap, long long int);
	/*
		flag traitement
	*/
	pointer(x);
	return (size_pointer(x)/* + flag size */);
}
