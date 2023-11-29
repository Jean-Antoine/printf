/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:50:41 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 11:59:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static size_t	ft_max(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

static void	ft_printfld(t_field *field)
{
	if (!field->str)
		return ;
	if (field->type == 'c')
		ft_putstr_f(field->str, ft_max(field->width, 1));
	else
		ft_putstr(field->str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_field	*fields;
	// t_field	*current;

	ft_putcount_reset();
	va_start(args, format);
	fields = ft_readformat((char *)format);
	ft_readparams(fields, args);
	// current = fields;
	// while (current)
	// {
	// 	printf("\nField values are :\ntype %c\nwidth %d\nprecision %d\nleft_align %d\nzero_padded %d\nforce_sign %d\nsign_char %c\nhex_prefix %d\nnegative %d\n",
	// 	current->type,
	// 	current->width,
	// 	current->precision,
	// 	current->left,
	// 	current->zero_padded,
	// 	current->force_sign,
	// 	current->sign_char,
	// 	current->hex_prefix,
	// 	current->negative);
	// 	if (current->str)
	// 		printf("str %s\n", current->str);
	// 	current = current->next;
	// }
	ft_fldmap(fields, ft_applyprecision);
	ft_fldmap(fields, ft_applysign);
	ft_fldmap(fields, ft_applyhexprefix);
	ft_fldmap(fields, ft_applywidth);
	ft_fldmap(fields, ft_printfld);
	ft_clearfldlst(&fields);
	return (ft_putcount_reset());
}
