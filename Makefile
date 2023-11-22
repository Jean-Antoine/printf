SRCS_D =				./srcs/
HEADER_D =				./include/
SRCS_F =				ft_printf.c\
						ft_putnbrbase.c\
						ft_putptr.c\
						ft_putchar.c\
						ft_putstr.c\
						ft_strlen.c
SRCS =					$(addprefix $(SRCS_D), $(SRCS_F))
OBJS =					$(SRCS:.c=.o)
NAME =					libftprintf.a
CC =					cc
CPPFLAGS =				-I$(HEADER_D)
CFLAGS =				-Wall -Wextra -Werror

all:					$(NAME)

$(NAME):				$(OBJS)
						ar rcs $(NAME) $(OBJS)

clean:
						rm -f $(OBJS)

fclean: 				clean
						rm -f $(NAME)

re: 					fclean all

test: 					$(NAME) main.c
						@$(CC) $(CPPFLAGS) $(CFLAGS) -o main main.c $(NAME)
						@./main
						@rm -f main main.o