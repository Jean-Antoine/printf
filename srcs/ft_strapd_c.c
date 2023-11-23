/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strapd_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:29:45 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/23 16:40:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

char	*ft_strapd_c(char *str, char c)
{
	size_t	length;
	char	*out;

	length = ft_strlen(str);
	out = (char *)ft_calloc(length + 2, sizeof(char));
	if (str)
	{
		ft_strlcpy(out, str, length + 1);
		free(str);
	}
	out[length] = c;
	return (out);
}