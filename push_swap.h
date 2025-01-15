/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:14 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 12:58:37 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "typedefs.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

t_nbr	set_min(t_list	*lst);
t_nbr	set_max(t_list *lst);
void	set_index(t_list *c1);

int		is_reverse_sorted(t_list *lst);;
int		is_sorted(t_list *lst);
int		is_circ_sorted(t_list *lst);

int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
int		ft_abs_val(int val);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	ft_swap(void *data1, void *data2, int size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
int		ft_strcmp(const char *s1, const char *s2);

void	pa(t_list	**lst_a, t_list	**lst_b, int mode);
void	pb(t_list	**lst_a, t_list	**lst_b, int mode);

void	ra(t_list **lst_a, int mode, t_cost *instruction);
void	rb(t_list **lst_b, int mode, t_cost *instruction);
void	rr(t_list **lst_a, t_list **lst_b, int mode, t_cost *instruction);

void	rra(t_list **lst_a, int mode, t_cost *instruction);
void	rrb(t_list **lst_b, int mode, t_cost *instruction);
void	rrr(t_list **lst_a, t_list **lst_b, int mode, t_cost *instruction);

void	sa(t_list **lst_a, int mode);
void	sb(t_list **lst_a, int mode);
void	ss(t_list **lst_a, t_list **lst_b, int mode);

void	init_cost(t_list *lst_a, t_list *lst_b, int size_a, int size_b);
t_cost	get_lower_cost(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int nb);
void	ft_swaplst(t_list **head, t_list *node1, t_list *node2);

int		create_list(char **arg, t_list **lst, int ac);
int		parse_error(t_list **lst);

void	ft_printlist(t_list *lst);
void	ft_printlist_index(t_list *lst);

t_list	*push_swap(t_list *lst_a);

#endif
