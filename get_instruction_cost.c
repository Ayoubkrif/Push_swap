/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:58:17 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 09:17:48 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_target_cost(t_list *lst, t_list *node, int size)
{
	t_nbr	min;
	t_nbr	max;
	int		i;

	i = 1;
	min = set_min(lst);
	max = set_max(lst);
	if (node->nbr < min.nbr || node->nbr > max.nbr)
	{
		node->cost.ra = min.rotate * min.info;
		return ;
	}
	while ((lst->next && !(node->nbr > lst->nbr && node->nbr < lst->next->nbr)))
	{
		lst = lst->next;
		i++;
	}
	if (!lst->next)
		node->cost.ra = 0;
	else if (i < size / 2)
		node->cost.ra = i;
	else
		node->cost.ra = i - size;
}

void	init_cost(t_list *lst_a, t_list *lst_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	while (lst_b)
	{
		if (i < size_b / 2)
			lst_b->cost.rb = i;
		else
			lst_b->cost.rb = i - size_b;
		init_target_cost(lst_a, lst_b, size_a);
		if ((lst_b->cost.ra > 0 && lst_b->cost.rb > 0)
			|| (lst_b->cost.ra < 0 && lst_b->cost.ra < 0))
				lst_b->total_cost = ft_max(ft_abs_val(lst_b->cost.rb),
					ft_abs_val(lst_b->cost.ra));
		else
				lst_b->total_cost = ft_abs_val(lst_b->cost.ra)
				+ ft_abs_val(lst_b->cost.rb);
		lst_b = lst_b->next;
		i++;
	}
}

t_cost	get_lower_cost(t_list *lst)
{
	t_list	*lower_cost;

	lower_cost = lst;
	while (lst)
	{
		if (lst->total_cost < lower_cost->total_cost)
			lower_cost = lst;
		lst = lst->next;
	}
	return (lower_cost->cost);
}
