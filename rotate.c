/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:28 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/09 15:59:59 by aykrifa          ###   ########.fr       */
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

void	ra(t_list **lst_a, int *count)
{
	rotate(lst_a);
	printf("ra\n");
	*count += 1;
}

void	rb(t_list **lst_b, int *count)
{
	rotate(lst_b);
	printf("rb\n");
	*count += 1;
}

void	rr(t_list **lst_a, t_list **lst_b, int *count)
{
	rotate(lst_b);
	rotate(lst_a);
	printf("rr\n");
	*count += 1;
}
