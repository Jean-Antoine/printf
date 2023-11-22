/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:50:41 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 12:04:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		writtenchar;

	writtenchar = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			continue ;
		}
		format++;
		if (*format == '%')
			ft_putchar(*format);
		else if (*format == 'c')
			ft_putchar(va_arg(args, int));
		else if (*format == 's')
			ft_putstr(va_arg(args, char *));
		else if (*format == 'p')
			ft_putptr(va_arg(args, void *));
		else if (*format == 'd' || *format == 'i')
			ft_putnbrbase(va_arg(args, int), "0123456789");
		else if (*format == 'u')
			ft_putnbrbase(va_arg(args, unsigned int), "0123456789");
		else if (*format == 'x')
			ft_putnbrbase(va_arg(args, unsigned int), "0123456789abcdef");
		else if (*format == 'X')
			ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF");
		format++;
	}
	return (writtenchar);
}