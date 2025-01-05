/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:28 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/04 17:37:01 by aykrifa          ###   ########.fr       */
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
