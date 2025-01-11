/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:53:46 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/10 16:54:12 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	*order4(t_list *lst, int *count)
{
	t_nbr	min;
	t_list	*last_node;
	t_list	*current;

	current = lst;
	min = set_min(lst);
	last_node = ft_lstlast(lst);
	last_node->next = lst;
	if (!is_circ_sorted(lst))
	{
		set_pos(lst);
		while (current->nbr != min.nbr)
			current = current->next;
		while (current < current->next)
			current = current->next;
		if (current->pos != 3)
		{
			while (current->pos)
			{
				ra(&lst, count);
				current->pos--;
			}
		}
		else
			rra(&lst, count);
		sa(&lst, count);
	}
	return (lst);
}
