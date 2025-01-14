/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:09:42 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 14:36:39 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_reverse_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->nbr < lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_circ_sorted(t_list *lst)
{
	t_nbr	max;
	t_list	*current;
	t_list	*last_node;

	last_node = ft_lstlast(lst);
	current = lst;
	max = set_max(lst);
	lst->prev = last_node;
	while (current->nbr != max.nbr)
		current = current->next;
	while (current->prev->nbr != max.nbr)
	{
		if (current->nbr < current->prev->nbr)
		{
			lst->prev = NULL;
			return (0);
		}
		current = current->prev;
	}
	lst->prev = NULL;
	return (1);
}
