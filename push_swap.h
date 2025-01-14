/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:14 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 17:59:25 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "typedefs.h"

t_nbr	set_min(t_list	*lst);
t_nbr	set_max(t_list *lst);
void	set_index(t_list *c1);
void	set_decile(t_list *lst);

int		is_reverse_sorted(t_list *lst);;
int		is_sorted(t_list *lst);
int		is_circ_sorted(t_list *lst);
int		ft_isdigit(int c);

int		ft_atoi(const char *nptr);
int		ft_abs_val(int val);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

void	pa(t_list	**lst_a, t_list	**lst_b, int *count);
void	pb(t_list	**lst_a, t_list	**lst_b, int *count);
void	ra(t_list **lst_a, int *count, t_cost *instruction);
void	rb(t_list **lst_b, int *count, t_cost *instruction);
void	rr(t_list **lst_a, t_list **lst_b, int *count, t_cost *instruction);
void	rra(t_list **lst_a, int *count, t_cost *instruction);
void	rrb(t_list **lst_b, int *count, t_cost *instruction);
void	rrr(t_list **lst_a, t_list **lst_b, int *count, t_cost *instruction);
void	sa(t_list **lst_a, int *count);
void	sb(t_list **lst_a, int *count);
void	ss(t_list **lst_a, t_list **lst_b, int *count);

void	init_cost(t_list *lst_a, t_list *lst_b, int size_a, int size_b);
t_cost	get_lower_cost(t_list *lst);

void	ft_swap(void *data1, void *data2, int size);
void	ft_swaplst(t_list **head, t_list *node1, t_list *node2);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_printlist(t_list *lst);
void	ft_printlist_index(t_list *lst);
void	ft_printlist_decile(t_list *lst);
t_list	*ft_lstnew(int nb);
int		create_list(char **arg, t_list **lst, int ac);
int		parse_error(t_list **lst);
void	ft_printlist(t_list *lst);

t_list	*push_swap(t_list *lst_a, int *count);

#endif
