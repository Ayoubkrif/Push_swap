/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:28:51 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/09 16:03:37 by aykrifa          ###   ########.fr       */
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

void	rra(t_list **lst_a, int *count)
{
	reverse_rotate(lst_a);
	printf("rra\n");
	*count += 1;
}

void	rrb(t_list **lst_b, int *count)
{
	reverse_rotate(lst_b);
	printf("rrb\n");
	*count += 1;
}

void	rrr(t_list **lst_a, t_list **lst_b, int *count)
{
	reverse_rotate(lst_b);
	reverse_rotate(lst_a);
	printf("rrr\n");
	*count += 1;
}
