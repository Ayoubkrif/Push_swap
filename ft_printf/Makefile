SRC = ft_printf.c ft_printf_c.c ft_printf_i.c \
	  ft_printf_s.c ft_printf_u.c  ft_printf_x.c \
	  ft_printf_X.c ft_printf_p.c ft_printf_per.c \
	  ft_putchar_count.c check_format.c ft_printer.c \
	  ft_putchar_fd.c ft_putstr_fd.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
