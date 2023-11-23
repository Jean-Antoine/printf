/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:42 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/23 17:14:15 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "-0.# +"
# define TYPES "cspdiuxX%"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

void	ft_putptr(void *ptr);
void	ft_putnbrbase(long long int n, char *base);
void	ft_putnbrbase_un(unsigned long long n, char *base);
int		ft_putchar_reset(void);
void	ft_putchar(int c);
void	ft_putstr(char *str);
int		ft_printf(const char *format, ...);
char	*ft_strapd_c(char *str, char c);
char	*ft_strppd_c(char *str, char c);

typedef struct	s_field
{
	char			*str;
	char			type;
	int				min_width;
	int				max_width;
	int				left_align;
	char			padded_char;
	int				force_sign;
	int				positive_blank;
	int				tag;
	struct s_field	*next;
}	t_field;

t_field	*ft_newfield(void);
void	ft_readformat(t_field **lst, char *format);
#endif
