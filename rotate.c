/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:28 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 15:12:33 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) == 1)
		return ;
	temp = (*lst);
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = NULL;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	ra(t_list **lst_a, int mode, t_cost *instruction)
{
	if (instruction)
		instruction->ra--;
	if (*lst_a)
		rotate(lst_a);
	if (mode)
		ft_printf("ra\n");
}

void	rb(t_list **lst_b, int mode, t_cost *instruction)
{
	if (instruction)
		instruction->rb--;
	if (*lst_b)
		rotate(lst_b);
	if (mode)
		ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list **lst_b, int mode, t_cost *instruction)
{
	if (instruction)
	{
		instruction->rb--;
		instruction->ra--;
	}
	if (*lst_b)
		rotate(lst_b);
	if (*lst_a)
		rotate(lst_a);
	if (mode)
		ft_printf("rr\n");
}
