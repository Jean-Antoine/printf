/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readparams.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:26 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/28 15:06:56 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ctostr(char c)
{
	char	*out;

	out = (char *)ft_calloc(2, sizeof(char));
	*out = c;
	return (out);
}

static char *ft_strdup_(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

void	ft_readparams(t_field *fields, va_list args)
{
	while (fields)
	{
		if (fields->min_width == -1)
			fields->min_width = va_arg(args, int);
		else if (fields->precision == -1)
			fields->precision = va_arg(args, int);
		else if (fields->type == '%')
			fields->str = ft_strdup("%");
		else if (fields->type == 'c')
			fields->str = ft_ctostr(va_arg(args, int));
		else if (fields->type == 's')
			fields->str = ft_strdup_(va_arg(args, char *));
		else if (fields->type == 'p')
			fields->str = ft_ptrtostr(va_arg(args, void *));
		else if (fields->type == 'd' || fields->type == 'i')
			fields->str = ft_itostr(va_arg(args, int), "0123456789");
		else if (fields->type == 'u')
			fields->str = ft_itostr(va_arg(args, unsigned int), "0123456789");
		else if (fields->type == 'x')
			fields->str = ft_itostr(va_arg(args, unsigned int), "0123456789abcdef");
		else if (fields->type == 'X')
			fields->str = ft_itostr(va_arg(args, unsigned int), "0123456789ABCDEF");
		fields = fields->next;
	}
}
