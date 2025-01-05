shuf -i 0-99 -n 100 | tr "\n" " " > list.txt
sed -i '$ s/.$//' list.txt
cc *.c libft/ft_atoi.c libft/ft_isdigit.c -g3 && ./a.out
