SRCS_D =				./srcs/
HEADER_D =				./include/
LIBFT_D =				./libft/
SRCS_F =				ft_printf.c\
						ft_itostr.c\
						ft_ptrtostr.c\
						ft_putstr.c\
						ft_strapd_c.c\
						ft_strppd_c.c\
						ft_newfld.c\
						ft_readformat.c \
						ft_readflags.c \
						ft_readparams.c \
						ft_strpadding.c \
						ft_applyprecision.c\
						ft_applysign.c \
						ft_applyhexprefix.c\
						ft_applywidth.c\
						ft_fldmap.c \
						ft_clearfldlst.c 
SRCS =					$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =					$(SRCS:.c=.o)
NAME =					libftprintf.a
LIBFT =					$(addprefix $(LIBFT_D), libft.a)
CC =					cc
CPPFLAGS =				-I$(HEADER_D) -I$(LIBFT_D)
CFLAGS =				-Wall -Wextra -Werror

all:					$(NAME)

$(LIBFT):
						make -C $(LIBFT_D)
						cp $(LIBFT) $(NAME)

$(NAME):				$(LIBFT) $(OBJS)
						ar rcs $(NAME) $(OBJS)

bonus:					$(NAME)

clean:
						make -C $(LIBFT_D) clean
						rm -f $(OBJS)

fclean: 				clean
						make -C $(LIBFT_D) fclean
						rm -f $(NAME)

re: 					fclean all

test: 					$(NAME) .main.c
						@$(CC) $(CPPFLAGS) $(CFLAGS) -o main .main.c $(NAME)
						./main
						@rm main