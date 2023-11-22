/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:21:26 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 11:48:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr)
{
	long long	p;

	p = (long long)ptr;
	ft_putstr("0x");
	ft_putnbrbase(p, "0123456789abcdef");
}
