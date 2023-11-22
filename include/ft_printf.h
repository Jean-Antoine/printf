/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:42 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 12:07:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<string.h>

int		ft_printf(const char *format, ...);
void	ft_putptr(void *ptr);
void	ft_putnbrbase(long long n, char *base);
int		ft_putchar_reset();
void	ft_putchar(int c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#endif
