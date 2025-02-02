/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:49:38 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 14:17:10 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		count;

	count = 0;
	lst = NULL;
	argv++;
	if (argc < 2 || (**argv) == 0)
		return (parse_error(&lst));
	if (argc == 2 && argv)
		argv = ft_split(*argv, ' ');
	if (!argv)
		return (parse_error(&lst));
	if (!create_list(argv, &lst, argc))
		return (parse_error(&lst));
	lst = push_swap(lst);
	ft_lstclear(&lst);
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

void	push_to_b(t_list **lst_a, t_list **lst_b, int size)
{
	int	median;

	median = get_median(*lst_a, size);
	while (size > 3)
	{
		pb(lst_a, lst_b, 1);
		if (median != -1 && (*lst_b)->index > median)
			rb(lst_b, 1, NULL);
		size--;
	}
}

void	repush_to_a(t_list **lst_a, t_list **lst_b)
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
			rrr(lst_a, lst_b, 1, &instruction);
		else if (instruction.ra > 0 && instruction.rb > 0)
			rr(lst_a, lst_b, 1, &instruction);
		else if (instruction.ra > 0)
			ra(lst_a, 1, &instruction);
		else if (instruction.ra < 0)
			rra(lst_a, 1, &instruction);
		else if (instruction.rb > 0)
			rb(lst_b, 1, &instruction);
		else
			rrb(lst_b, 1, &instruction);
	}
	pa(lst_a, lst_b, 1);
}

t_list	*push_swap(t_list *lst_a)
{
	t_list	*lst_b;
	t_nbr	min;
	int		size;

	lst_b = NULL;
	size = ft_lstsize(lst_a);
	push_to_b(&lst_a, &lst_b, size);
	if (!is_circ_sorted(lst_a))
		sa(&lst_a, 1);
	while (lst_b)
		repush_to_a(&lst_a, &lst_b);
	min = set_min(lst_a);
	if (min.rotate && (min.info == 1))
		while (!is_sorted(lst_a))
			ra(&lst_a, 1, NULL);
	else if (min.rotate)
		while (!is_sorted(lst_a))
			rra(&lst_a, 1, NULL);
	return (lst_a);
}
