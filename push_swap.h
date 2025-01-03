/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:14 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/03 11:30:16 by aykrifa          ###   ########.fr       */
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

t_nbr	set_min(t_list	*lst);
t_nbr	set_max(t_list *lst);
t_nbr	set_closest(t_list	*lst);
t_nbr	set_closest_decile(t_list *lst, int find);
t_nbr	set_rotate_closest_decile(t_list *lst, int find);
t_nbr	set_reverse_closest_decile(t_list *lst, int find);
void	set_index(t_list *c1);
void	set_decile(t_list *lst);

int	is_reverse_sorted(t_list *lst);;
int	is_sorted(t_list *lst);
int	is_ordered(t_list *lst);
int	find_median(t_list *lst);
int	decile_finder(t_list *lst, int find);


void	pa(t_list	**lst_a, t_list	**lst_b, int *count);
void	pb(t_list	**lst_a, t_list	**lst_b, int *count);
void	rotate(t_list **lst, int *count);
void	reverse_rotate(t_list **lst, int *count);
void	lst_swap(t_list	**lst, int *count);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_front(t_list **lst, t_list *node);

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_printlist(t_list *lst);
void	ft_printlist_index(t_list *lst);
void	ft_printlist_decile(t_list *lst);
t_list	*ft_lstnew(int nb);
t_list	*create_list(void);
t_list	*ft_lstdup(t_list *lst);

t_list	*push_swap(t_list *lst_a,int *count);

#endif
