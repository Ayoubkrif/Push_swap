SRC = check_lst.c ft_swaplst.c get_next_line.c \
	  get_next_line_utils.c main.c \
	  parse.c push.c reverse_rotate.c rotate.c swap.c \
	  utils.c

LBS = libft.a

LBSDIR = libft

OBJ = $(SRC:.c=.o)

NAME = push_swap

CC = cc

CFLAGS =# -Wall -Wextra -Werror

all : libft.a $(NAME)

$(NAME):
	$(CC) -o $(NAME) *.c -g3

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

libft.a :
	make -C libft
	cp libft/libft.a libft.a

clean :
	rm -rf *.o

fclean : clean
	rm -rf *.a

re : fclean all

clean_libft :
	make clean -C $(LBSDIR)

fclean_libft :
	make fclean -C $(LBSDIR)

re_libft :
	make re -C $(LBSDIR)

clean_all : clean clean_libft

fclean_all : clean_all fclean fclean_libft

re_all : re_libft re
