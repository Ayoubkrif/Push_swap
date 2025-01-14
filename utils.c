/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:03:17 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 13:12:03 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *c1)
{
	t_list	*c2;

	if (!c1->next)
		return ;
	while (c1)
	{
		c2 = c1->next;
		while (c2)
		{
			if (c2->nbr > c1->nbr)
				c2->index++;
			else
				c1->index++;
			c2 = c2->next;
		}
		c1 = c1->next;
	}
}

static t_nbr	fill_t_nbr(int nbr, int index, int rotate, int info)
{
	t_nbr	to_fill;

	to_fill.nbr = nbr;
	to_fill.index = index;
	to_fill.rotate = rotate;
	to_fill.info = info;
	return (to_fill);
}

t_nbr	set_min(t_list	*lst)
{
	t_nbr	min;
	int		stack_pos;
	int		lst_size;

	lst_size = ft_lstsize(lst);
	stack_pos = 0;
	min.nbr = lst->nbr;
	while (lst)
	{
		if (min.nbr >= lst->nbr)
		{
			if (stack_pos <= (lst_size / 2))
				min = fill_t_nbr(lst->nbr, lst->index,
						stack_pos, 1);
			else
				min = fill_t_nbr(lst->nbr, lst->index,
						lst_size - stack_pos, -1);
		}
		lst = lst->next;
		stack_pos++;
	}
	return (min);
}

t_nbr	set_max(t_list *lst)
{
	t_nbr	max;
	int		stack_pos;
	int		lst_size;

	stack_pos = 0;
	lst_size = ft_lstsize(lst);
	max.nbr = lst->nbr;
	while (lst)
	{
		if (max.nbr <= lst->nbr)
		{
			if (stack_pos <= (lst_size / 2))
				max = fill_t_nbr(lst->nbr, lst->index,
						stack_pos, 1);
			else
				max = fill_t_nbr(lst->nbr, lst->index,
						lst_size - stack_pos, -1);
		}
		lst = lst->next;
		stack_pos++;
	}
	return (max);
}
