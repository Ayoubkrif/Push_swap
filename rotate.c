/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:28 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/07 09:32:58 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst, int *count)
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
	*count += 1;
}

void	ra(t_list **lst_a, int *count)
{
	rotate(lst_a, count);
	printf("ra\n");
}

void	rb(t_list **lst_b, int *count)
{
	rotate(lst_b, count);
	printf("rb\n");
}

void	rr(t_list *lst_a, t_list *lst_b, int *count)
{
	printf("rr\n");
}
