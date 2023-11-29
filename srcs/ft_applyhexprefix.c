/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyhexprefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:39:16 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 12:02:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_applyhexprefix(t_field *field)
{
	if (!(field->hex_prefix && (field->type == 'x' || field->type == 'X')))
		return ;
	if (field->str[0] == '0' && !field->str[1])
		return ;
	field->str = ft_strppd_c(field->str, field->type);
	field->str = ft_strppd_c(field->str, '0');
}
