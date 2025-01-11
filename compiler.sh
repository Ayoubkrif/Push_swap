shuf -i 2-4 -n 3 | tr "\n" " " > list.txt
sed -i '$ s/.$//' list.txt
echo -n "3 2 4" > list.txt
cc *.c libft/ft_atoi.c libft/ft_isdigit.c -g3 && ./a.out
