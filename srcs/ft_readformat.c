/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:17:52 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/23 17:25:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_readformat(t_field **lst, char *format)
{
	t_field	*field;

	field = ft_newfield();
	*lst = field;
	while (*format)
	{
		if (*format != '%')
		{
			field->str = ft_strapd_c(field->str, *format++);
			continue ;
		}
		format++;
		ft_readflags(format, field);
		while (ft_strchr(FLAGS, *format))
			format++;
		field->type = *format++;
		field->next = ft_newfield();
		field = field->next;
	}
}



