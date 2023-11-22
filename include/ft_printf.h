/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:42 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 13:41:21 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

void	ft_putptr(void *ptr);
void	ft_putnbrbase(long long int n, char *base);
void	ft_putnbrbase_un(unsigned long long n, char *base);
int		ft_putchar_reset(void);
void	ft_putchar(int c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *format, ...);

#endif
