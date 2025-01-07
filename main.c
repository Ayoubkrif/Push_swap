/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:38 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/07 17:12:46 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	printf("%d\n", is_ordered(lst));
}

void	push_to_b(t_list **lst_a, t_list **lst_b, t_nbr to_push, int *count)
{
	if (to_push.info < 0)
	{
		while (to_push.rotate != 0)
		{
			rra(lst_a, count);
			to_push.rotate--;
		}
	}
	else
	{
		while (to_push.rotate != 0)
		{
			ra(lst_a, count);
			to_push.rotate--;
		}
	}
	pb(lst_a, lst_b, count);
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
	i = 1;
	while (i <= 6)
	{
		while (decile_counter(lst_a, i) != 1)
		{
			to_push = set_closest_decile(lst_a, i);
			push_to_b(&lst_a, &lst_b, to_push, count);
		}
		i++;
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
