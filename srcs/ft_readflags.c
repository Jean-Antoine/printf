/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:58:58 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/27 20:55:37 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_readflags(char *format, t_field *field)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			field->left_align = 1;
		else if (*format == '0')
			field->padded_char = '0';
		else if (*format == '+')
			field->force_sign = 1;
		else if (*format == ' ')
			field->positive_blank = 1;
		else if (*format == '#')
			field->tag = 1;
		else if (*format == '.' || ft_isdigit(*format) || *format == '*')
		{
			ft_readlimits(field, format);
			while (*format == '.' || ft_isdigit(*format) || *format == '*')
				format++;
			format--;
		}
		format++;
	}
}

static void	ft_readlimits(t_field *field, char *format)
{
	if (ft_isdigit(*format) || *format == '*')
	{
		if (*format == '*')
			field->min_width = -1;
		else
			field->min_width = ft_atoi(format);
		while (ft_isdigit(*format) || *format == '*')
			format ++;
	}
	if (*format == '.')
	{
		format++;
		if (ft_isdigit(*format) || *format == '*')
		{
			if (*format == '*')
				field->max_width = -1;
			else
				field->max_width = ft_atoi(format);
			while (ft_isdigit(*format) || *format == '*')
				format ++;
		}
	}
}
