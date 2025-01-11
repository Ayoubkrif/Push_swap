/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:14 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/10 16:46:22 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int				nbr;
	int				index;
	int				decile;
	int				pos;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

typedef struct s_nbr
{
	int	nbr;
	int	index;
	int	rotate;
	int	info;
}t_nbr;

//t_nbr	set_min(t_list	*lst);
t_nbr	set_max(t_list *lst);
//t_nbr	set_closest(t_list	*lst);
t_nbr	set_closest_decile(t_list *lst, int find);
t_nbr	set_rotate_closest_decile(t_list *lst, int find);
t_nbr	set_reverse_closest_decile(t_list *lst, int find);
void	set_index(t_list *c1);
void	set_decile(t_list *lst);

int		is_reverse_sorted(t_list *lst);;
int		is_sorted(t_list *lst);
int		is_circ_sorted(t_list *lst);
//int		find_median(t_list *lst);
int		decile_counter(t_list *lst, int find);

void	pa(t_list	**lst_a, t_list	**lst_b, int *count);
void	pb(t_list	**lst_a, t_list	**lst_b, int *count);
void	ra(t_list **lst_a, int *count);
void	rb(t_list **lst_b, int *count);
void	rr(t_list **lst_a, t_list **lst_b, int *count);
void	rra(t_list **lst_a, int *count);
void	rrb(t_list **lst_b, int *count);
void	rrr(t_list **lst_a, t_list **lst_b, int *count);
void	sa(t_list **lst_a, int *count);
void	sb(t_list **lst_a, int *count);
void	ss(t_list **lst_a, t_list **lst_b, int *count);

void	ft_swap(void *data1, void *data2, int size);
void	ft_swaplst(t_list **head, t_list *node1, t_list *node2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_front(t_list **lst, t_list *node);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_printlist(t_list *lst);
void	ft_printlist_index(t_list *lst);
void	ft_printlist_decile(t_list *lst);
t_list	*ft_lstnew(int nb);
t_list	*create_list(void);

t_list	*push_swap(t_list *lst_a, int *count);

#endif
