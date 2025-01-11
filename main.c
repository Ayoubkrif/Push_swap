/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:38 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/11 16:29:34 by aykrifa          ###   ########.fr       */
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

void	push_to_b(t_list **lst_a, t_list **lst_b, int *count)
{
	int	median;
	int	size;

	size = ft_lstsize(*lst_a);
	median = get_median(*lst_a, size);
	while (size > 3)
	{
		pb(lst_a, lst_b, count);
		if ((*lst_b)->index > median)
			rb(lst_b, count);
		size--;
	}
}

void	repush_to_a(t_list **lst_a, t_list **lst_b, t_nbr to_push, int *count)
{
	if (to_push.info < 0)
	{
		while (to_push.rotate != 0)
		{
			rrb(lst_b, count);
			to_push.rotate--;
		}
	}
	else
	{
		while (to_push.rotate != 0)
		{
			rb(lst_b, count);
			to_push.rotate--;
		}
	}
	pa(lst_a, lst_b, count);
}

t_list	*push_swap(t_list *lst_a, int *count)
{
	t_list	*lst_b;
	t_nbr	to_push;
	int		i;

	lst_b = NULL;
	push_to_b(&lst_a, &lst_b, count);
	while (lst_b)
	{
		repush_to_a(&lst_a, &lst_b, *count);
	}
	ft_printlist(lst_b);
	printf("%d pour push to b\n", *count);
	return (lst_a);
	while (lst_b)
	{
		to_push = set_max(lst_b);
		repush_to_a(&lst_a, &lst_b, to_push, count);
	}
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
