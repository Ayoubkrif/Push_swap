/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:38 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/11 18:57:01 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*sort3(t_list *lst, int *count);

int	main(void)
{
	t_list	*lst;
	int		count;

	count = 0;
	lst = create_list();
	ft_printlist(lst);
	/*set_index(lst);
	set_decile(lst);
	printf("liste ------------\n");
	ft_printlist(lst);
	printf("index ------------\n");
	ft_printlist_index(lst);
	printf("decile------------\n");
	ft_printlist_decile(lst);
	lst = push_swap(lst, &count);
	printf("lst final------------\n");
	ft_printlist(lst);
	printf("%d coups !\n", count);
	ft_printlist_index(lst);
	printf("decile------------\n");
	ft_printlist_decile(lst);*/
	lst = sort3(lst, &count);
	ft_printlist(lst);
	printf("%d coups !\n", count);
	ft_lstadd_back(&lst, ft_lstnew(5));
	ft_swaplst(&lst, lst, ft_lstlast(lst));
	ft_printlist(lst);
}

int	get_median(t_list *lst_a, int size)
{
	set_index(lst_a);
	if (size > 100)
		while (lst_a->index != size / 2)
			lst_a = lst_a->next;
	else
		return (-1);
	return (lst_a->index);
}

void	push_to_b(t_list **lst_a, t_list **lst_b, int *count, int size)
{
	int	median;
	int	size;

	median = get_median(*lst_a, size);
	while (size > 3)
	{
		pb(lst_a, lst_b, count);
		if ((*lst_b)->index > median)
			rb(lst_b, count);
		size--;
	}
}

void	init_target(t_list *lst_a, t_list *lst_b)
{
	t_nbr	max;
	t_nbr	min;
	t_list	*current;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = set_max(lst_a);
	min = set_min(lst_a);
	if (lst_b->nbr < min.nbr || lst_b->nbr > max.nbr)
	{
		lst_b->target = min.nbr;
		return ;
	}
	current = lst_a;
	while (current->next
		&& !(lst_b->nbr > current->nbr && lst_b->nbr < current->next->nbr))
		current = current->next;
	if (current->next)
		lst_b->target = current->next->nbr;
	else
		lst_b->target = lst_a->nbr;
}

int	abs_val(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

void	init_target_cost(t_list *lst, t_list *node, int size)
{
	t_nbr	min;
	t_nbr	max;
	int		i;
	t_list	*last_node;

	i = 0;
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
	if (i < size / 2)
		node->cost.ra = i;
	else
		node->cost.ra = i - size;
}

void	init_cost(t_list *lst_a,t_list *lst_b, int size_a, int size_b)
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
				lst_b->total_cost = abs_val(lst_b->cost.rb + lst_b->cost.ra);
		else
				lst_b->total_cost = abs_val(lst_b->cost.ra)
				+ abs_val(lst_b->cost.rb);
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

void	repush_to_a(t_list **lst_a, t_list **lst_b, int *count)
{
	t_cost	instruction;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*lst_a);
	size_b = ft_lstsize(*lst_b);
	init_cost(*lst_a, *lst_b, size_a, size_b);
	instruction = get_lower_cost(*lst_b);
	while (instruction.ra || instruction.rb)
	{
		if (instruction.ra < 0 && instruction.rb < 0)
			rrr(lst_a, lst_b, count, &instruction);
		else if (instruction.ra > 0 && instruction.rb > 0)
			rr(lst_a, lst_b, count, &instruction);
		else if (instruction.ra > 0)
			ra(lst_a, count, &instruction);
		else if (instruction.ra < 0)
			rra(lst_a, count, &instruction);
		else if (instruction.rb > 0)
			rb(lst_b, count, &instruction);
		else
			rrb(lst_b, count, &instruction);
	}
}

t_list	*push_swap(t_list *lst_a, int *count)
{
	t_list	*lst_b;
	t_nbr	min;
	int		size;

	lst_b = NULL;
	size = ft_lstsize(lst_a);
	push_to_b(&lst_a, &lst_b, count, size);
	if (!is_circ_sorted(lst_a))
		sa(&lst_a, count);
	while (lst_b)
		repush_to_a(&lst_a, &lst_b, count);
	min = set_min(lst_a);
	if (min.rotate && (min.info == 1 || size > 2))
		while (!is_sorted(lst_a))
			ra(&lst_a, count, NULL);
	else if (min.rotate)
		while (!is_sorted(lst_a))
			rra(&lst_a, count, NULL);
	return (lst_a);
}

t_list	*bubble_sorting(t_list *lst_a, int *count)
{
	t_nbr	max;
	t_list	*lst_b;

	max = set_max(lst_a);
	while (!is_circ_sorted(lst_a))
	{
		if (lst_a->nbr > lst_a->next->nbr && lst_a->nbr != max.nbr)
		{
			sa(&lst_a, count);
		}
		ra(&lst_a, count);
	}
	return (lst_a);
}
