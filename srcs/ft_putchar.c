/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:28:31 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 11:44:09 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

static int ft_putchar_counter(int c, int reset)
{
	static int	i;
	int			out;

	if (reset)
	{
		out = i;
		i = 0;
		return (out);
	}
	write(1, &c, 1);
	i++;
	return (i);
}

int ft_putchar_reset()
{
	return(ft_putchar_counter(0, 1));
}

void	ft_putchar(int c)
{	
	ft_putchar_counter(c, 0);
}