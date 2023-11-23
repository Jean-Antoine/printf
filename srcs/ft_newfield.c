/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:45 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/23 17:14:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_field	*ft_newfield(void)
{
	t_field	*field;

	field = (t_field *)ft_calloc(1, sizeof(t_field));
	field->str = NULL;
	field->type = 0;
	field->min_width = 0;
	field->max_width = 0;
	field->left_align = 0;
	field->padded_char = ' ';
	field->force_sign = 0;
	field->positive_blank = 0;
	field->next = NULL;
	field->tag = 0;
	return (field);
}