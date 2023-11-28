/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:50:41 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/28 14:00:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_field	*fields;
	t_field	*current;

	va_start(args, format);
	fields = ft_readformat((char *)format);
	ft_readparams(fields, args);
	current = fields;
	while (current)
	{
		printf("\nField values are :\ntype %c\nmin_width %d\nmax_width %d\nleft_align %d\npadded_char %c\nforce_sign %d\npositive_blank %d\ntag %d\n",
		current->type,
		current->min_width,
		current->max_width,
		current->left_align,
		current->padded_char,
		current->force_sign,
		current->positive_blank,
		current->tag);
		if (current->str)
			printf("str %s\n", current->str);
		current = current->next;
	}
	ft_clearfldlst(&fields);
	return (1);
}
