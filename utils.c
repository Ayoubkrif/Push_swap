/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:03:17 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/11 16:06:14 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_decile(t_list *lst)
{
	while (lst)
	{
		if (lst->index <= 16)
			lst->decile = 1;
		if (lst->index >= 17 && lst->index <= 32)
			lst->decile = 2;
		if (lst->index >= 33 && lst->index <= 49)
			lst->decile = 3;
		if (lst->index >= 50 && lst->index <= 65)
			lst->decile = 4;
		if (lst->index >= 66 && lst->index <= 82)
			lst->decile = 5;
		if (lst->index >= 83)
			lst->decile = 6;
		lst = lst->next;
	}
}
/*
 * 00 - 16
 * 17 - 32
 * 33 - 49
 * 50 - 65
 * 66 - 82
 * 83 - 99
*/
int	decile_counter(t_list *lst, int find)
{
	int	n;

	n = 0;
	while (lst)
	{
		if (lst->decile == find)
			n++;
		lst = lst->next;
	}
	return (n);
}

t_nbr	set_closest_decile(t_list *lst, int find)
{
	t_nbr	reverse_rotate;
	t_nbr	rotate;

	reverse_rotate = set_reverse_closest_decile(lst, find);
	rotate = set_rotate_closest_decile(lst, find);
	if (reverse_rotate.rotate < rotate.rotate)
		return (reverse_rotate);
	return (rotate);
}

t_nbr	set_reverse_closest_decile(t_list *lst, int find)
{
	t_nbr	reverse_rotate;
	t_list	*current;
	int		nrotate;

	current = ft_lstlast(lst);
	nrotate = 1;
	while (current->decile != find)
	{
		current = current->prev;
		nrotate++;
	}
	reverse_rotate.index = current->index;
	reverse_rotate.rotate = nrotate;
	reverse_rotate.info = -1;
	reverse_rotate.nbr = current->nbr;
	return (reverse_rotate);
}

t_nbr	set_rotate_closest_decile(t_list *lst, int find)
{
	t_nbr	rotate;
	t_list	*current;
	int		nrotate;

	current = lst;
	nrotate = 0;
	while (current->decile != find)
	{
		current = current->next;
		nrotate++;
	}
	rotate.index = current->index;
	rotate.rotate = nrotate;
	rotate.info = 1;
	rotate.nbr = current->nbr;
	return (rotate);
}

int	is_unique(t_list *c1)
{
	t_list	*c2;

	if (!c1->next)
		return (1);
	while (c1)
	{
		c2 = c1->next;
		while (c2)
		{
			if (c2->nbr == c1->nbr)
				return (0);
			c2 = c2->next;
		}
		c1 = c1->next;
	}
	return (1);
}

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

t_nbr	fill_t_nbr(int nbr, int index, int rotate, int info)
{
	t_nbr	to_fill;

	printf("nbr %d, index : %d , rotate %d info %d\n", nbr, index, rotate, info);
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
	int	lst_size;

	printf("a\n");
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
/*
t_nbr	set_closest(t_list	*lst)
{
	t_nbr	min;
	t_nbr	max;

	min = set_min(lst);
	max = set_max(lst);
	if (min.rotate < max.rotate)
	{
		if (min.index > (ft_lstsize(lst) / 2))
			min.rotate = min.rotate * (-1);
		return (min);
	}
	else
	{
		if (max.index > (ft_lstsize(lst) / 2) - 1)
			max.rotate = max.rotate * (-1);
		return (max);
	}
}*/

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

t_list	*sort3(t_list *lst, int *count)
{
	t_nbr	min;

	if (!is_circ_sorted(lst))
		sa(&lst, count);
	min = set_min(lst);
	while (min.rotate > 0)
	{
		if (min.info > 0)
			ra(&lst, count);
		else
			rra(&lst, count);
		min.rotate--;
	}
	return (lst);
}

void	set_pos(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->pos = i;
		lst = lst->next;
		i++;
	}
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

t_list	*sort5()
