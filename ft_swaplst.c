/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:08:20 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 13:20:45 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lstswap(t_list **l1, t_list **l2)
{
	t_list	*temp;

	temp = *l1;
	*l1 = *l2;
	*l2 = temp;
}

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
	lstswap(&(node1)->next, &(node2)->next);
	lstswap(&(node1)->prev, &(node2)->prev);
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
