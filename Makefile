SRC = check_lst.c display_lst.c ft_abs_val.c lst_utils.c \
	  ft_atol.c ft_freelst.c ft_isdigit.c parse.c \
	  ft_lstlast.c push.c ft_lstsize.c ft_max.c reverse_rotate.c \
	  ft_min.c rotate.c swap.c ft_split.c ft_swaplst.c utils.c \
	  get_instruction_cost.c main.c

BONUS_SRC = checker.c ft_strcmp.c check_lst.c display_lst.c \
			ft_abs_val.c lst_utils.c ft_atol.c ft_freelst.c \
			ft_isdigit.c parse.c ft_lstlast.c push.c ft_lstsize.c \
			ft_max.c reverse_rotate.c ft_min.c rotate.c swap.c \
			ft_split.c ft_swaplst.c utils.c get_instruction_cost.c \
			get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = push_swap

BONUS_NAME = checker

LBSDIR = ft_printf

LBS = ft_printf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : printf $(NAME)

bonus : printf $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJ) -L. $(LBS)

printf :
	make -C $(LBSDIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L. $(LBS)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(BONUS_OBJ) : $(BONUS_SRC)
	$(CC) $(CFLAGS) -c $(BONUS_SRC)

clean :
	rm -f $(OBJ) $(BONUS_OBJ)
	make clean -C $(LBSDIR)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(LBS)

re : fclean all

test: all bonus
	@for i in 0 1 2 3 4; do \
		for j in 0 1 2 3 4; do \
			for k in 0 1 2 3 4; do \
				for l in 0 1 2 3 4; do \
					for m in 0 1 2 3 4; do \
						if [ "$$i" != "$$j" ] && [ "$$i" != "$$k" ] && [ "$$i" != "$$l" ] && [ "$$i" != "$$m" ] && \
						   [ "$$j" != "$$k" ] && [ "$$j" != "$$l" ] && [ "$$j" != "$$m" ] && \
						   [ "$$k" != "$$l" ] && [ "$$k" != "$$m" ] && [ "$$l" != "$$m" ]; then \
							ARG="$$i $$j $$k $$l $$m"; ./push_swap $$ARG | ./checker $$ARG; \
						fi; \
					done; \
				done; \
			done; \
		done; \
	done
