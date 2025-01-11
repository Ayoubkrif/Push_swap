/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:34:59 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/10 16:31:50 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	not_adjacent_nodes(t_list *node1, t_list *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->prev)
		node2->prev->next = node1;
	if (node1->next)
		node1->next->prev = node2;
	if (node2->next)
		node2->next->prev = node1;
	ft_swap(&(node1)->next, &(node2)->next, sizeof(t_list *));
	ft_swap(&(node1)->prev, &(node2)->prev, sizeof(t_list *));
}

void	node1_before(t_list *node1, t_list *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	node1->prev = node2;
	node2->next = node1;
}

void	node2_before(t_list *node1, t_list *node2)
{
	node2->next = node1->next;
	if (node1->next)
		node1->next->prev = node2;
	node1->prev = node2->prev;
	if (node2->prev)
		node2->prev->next = node1;
	node2->prev = node1;
	node1->next = node2;
}

void	ft_swaplst(t_list **head, t_list *node1, t_list *node2)
{
	if (node1 == node2)
		return ;
	if (node1->next != node2 && node2->next != node1)
		not_adjacent_nodes(node1, node2);
	else if (node1->next == node2)
		node1_before(node1, node2);
	else if (node2->next == node1)
		node2_before(node1, node2);
	if (node1 == *head)
		*head = node2;
	else if (node2 == *head)
		*head = node1;
}

void	sa(t_list **lst_a, int *count)
{
	ft_swaplst(lst_a, *lst_a, (*lst_a)->next);
	*count += 1;
	printf("sa\n");
}

void	sb(t_list **lst_b, int *count)
{
	ft_swaplst(lst_b, *lst_b, (*lst_b)->next);
	*count += 1;
	printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b, int *count)
{
	ft_swaplst(lst_a, *lst_a, (*lst_a)->next);
	ft_swaplst(lst_b, *lst_b, (*lst_b)->next);
	*count += 1;
	printf("ss\n");
}
