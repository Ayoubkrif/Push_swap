/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:28:51 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/07 09:30:01 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **lst, int *count)
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
	*count += 1;
}

void	rra(t_list **lst_a, int *count)
{
	reverse_rotate(lst_a, count);
	printf("rra\n");
}

void	rrb(t_list **lst_b, int *count)
{
	reverse_rotate(lst_b, count);
	printf("rrb\n");
}

void	rrr(t_list *lst_a, t_list *lst_b, int *count)
{
	printf("rrr\n");
}
