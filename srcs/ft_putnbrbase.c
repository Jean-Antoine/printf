/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:29:51 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 12:06:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_anydup(char *str)
{
	char	*str_s;

	while (*str)
	{
		str_s = str + 1;
		while (*str_s)
			if (*str_s++ == *str)
				return (1);
		str++;
	}
	return (0);
}

static void	ft_putnbrbase_rec(long long n, char *base, int size)
{
	if (n < size)
	{
		ft_putchar(base[n]);
		return ;
	}
	ft_putnbrbase_rec(n / size, base, size);
	ft_putchar(base[n % size]);
	return ;
}

void	ft_putnbrbase(long long n, char *base)
{
	int	size;

	if (!base || ft_anydup(base))
		return ;
	size = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putnbrbase_rec(n, base, size);
	return ;
}
