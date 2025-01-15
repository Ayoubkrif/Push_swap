/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:28:51 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 15:13:10 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*current;
	t_list	*temp;

	current = *lst;
	if (ft_lstsize(*lst) == 1)
		return ;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	ft_lstadd_front(lst, temp);
}

void	rra(t_list **lst_a, int mode, t_cost *instruction)
{
	if (instruction)
		instruction->ra++;
	if (*lst_a)
		reverse_rotate(lst_a);
	if (mode)
		ft_printf("rra\n");
}

void	rrb(t_list **lst_b, int mode, t_cost *instruction)
{
	if (instruction)
		instruction->rb++;
	if (*lst_b)
		reverse_rotate(lst_b);
	if (mode)
		ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list **lst_b, int mode, t_cost *instruction)
{
	if (instruction)
	{
		instruction->rb++;
		instruction->ra++;
	}
	if (*lst_b)
		reverse_rotate(lst_b);
	if (*lst_a)
		reverse_rotate(lst_a);
	if (mode)
		ft_printf("rrr\n");
}
