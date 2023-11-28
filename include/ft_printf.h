/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:24:42 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/28 15:21:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "-0# +"
# define TYPES "cspdiuxX%"
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

void	ft_putptr(void *ptr);
char	*ft_itostr(long long int n, char *base);
char	*ft_uitostr(size_t n, char *base);
char	*ft_ptrtostr(void *ptr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_putcount_reset(void);
void	ft_putstr(char *str);
int		ft_printf(const char *format, ...);
char	*ft_strapd_c(char *str, char c);
char	*ft_strppd_c(char *str, char c);

typedef struct	s_field
{
	char			*str;
	char			type;
	int				min_width;
	int				precision;
	int				left_align;
	char			padded_char;
	int				force_sign;
	int				positive_blank;
	int				tag;
	struct s_field	*next;
}	t_field;

t_field	*ft_newfield(void);
void	ft_clearfldlst(t_field **lst);
void	ft_readflags(char *format, t_field *field);
t_field	*ft_readformat(char *format);
void	ft_readparams(t_field *fields, va_list args);
#endif
