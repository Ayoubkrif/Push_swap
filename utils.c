/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:03:17 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/03 12:05:57 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	decile_finder(t_list *lst, int find)
{
	while (lst)
	{
		if (lst->decile == find)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_nbr	set_closest_decile(t_list *lst, int find)
{
	t_nbr	reverse_rotate;
	t_nbr	rotate;

	rotate = set_rotate_closest_decile(lst, find);
	reverse_rotate = set_reverse_closest_decile(lst, find);
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
	reverse_rotate.info = -1;//reverse rotate.
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
	rotate.info = 1;//reverse rotate.
	rotate.nbr = current->nbr;
	return (rotate);
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

t_nbr	set_min(t_list	*lst)
{
	t_list	*current;
	t_nbr	min;
	int i;

	min.index = 0;
    min.nbr = lst->nbr;
    current = lst;
	min.info = 0;
    while (current)
	{
		if (min.nbr > current->nbr)
		{
			min.index = i;
			min.nbr = current->nbr;
		}
		i++;
		current = current->next;
    }
	if (min.index < (ft_lstsize(lst) / 2))
		min.rotate = min.index;
	else
		min.rotate = ft_lstsize(lst) - min.index;
	return (min);
}

t_nbr	set_max(t_list *lst)
{
	t_list	*current;
	t_nbr	max;
	int i;

	max.index = 0;
    max.nbr = lst->nbr;
    current = lst;
	max.info = 1;
    while (current)
	{
		if (max.nbr < current->nbr)
		{
			max.index = i;
			max.nbr = current->nbr;
		}
		i++;
		current = current->next;
    }
	if (max.index < (ft_lstsize(lst) / 2)) 
		max.rotate = max.index;
	else
		max.rotate = ft_lstsize(lst) - max.index;
	return (max);
}

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
}
int is_reverse_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->nbr < lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	printf("is reverse sorted !\n");
	return (1);
}

int is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst = lst->next;
	}
	//printf("is sorted !\n");
	return (1);
}

int is_ordered(t_list *lst)
{
	t_nbr	min;
	int		i;
	t_list *temp;

	printf("is ordered ? :");
	ft_printlist(lst);
	i = 0;
	temp = lst;
	min = set_min(temp);
	/*while (temp->nbr != min.nbr)
		rotate(&temp, &i);*/
	printf("fin\n");
	if (!is_sorted(temp))
		return(0);
	printf("clock ordered !\n");
	return (1);
}

int find_median(t_list *lst)
{
	int i;
	t_list *current;
	int median;

	i = ft_lstsize(lst);
	while (current)
	{

		current = current->next;
	}
	return (1);
}

void	set_index_to_zero(t_list *lst)
{
	while (lst)
	{
		lst->index = 0;
		lst = lst->next;
	}
}
