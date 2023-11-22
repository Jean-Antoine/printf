SRCS_D =				./srcs/
HEADER_D =				./include/
LIBFT_D =				./libft/
SRCS_F =				ft_printf.c\
						ft_putnbrbase.c\
						ft_putptr.c\
						ft_putchar.c\
						ft_putstr.c\
						ft_strlen.c
SRCS =					$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =					$(SRCS:.c=.o)
NAME =					libftprintf.a
LIBFT =					$(addprefix $(LIBFT_D), libft.a)
CC =					cc
CPPFLAGS =				-I$(HEADER_D) -I$(LIBFT_D)
CFLAGS =				-Wall -Wextra -Werror

all:					$(NAME)

$(NAME):				$(LIBFT) $(OBJS)
						ar rcs $(NAME) $(OBJS)

$(LIBFT):
						make -C $(LIBFT_D)
						cp $(LIBFT) $(NAME)

clean:
						make -C $(LIBFT_D) clean
						rm -f $(OBJS)

fclean: 				clean
						make -C $(LIBFT_D) fclean
						rm -f $(NAME)

re: 					fclean all

test: 					$(NAME) main.c
						@$(CC) $(CPPFLAGS) $(CFLAGS) -c main.c 
						@$(CC) $(CPPFLAGS) $(CFLAGS) -o main main.o $(NAME)
						@./main
						@rm -f main main.o