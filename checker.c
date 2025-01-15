/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:34:58 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 15:11:16 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	check_instruction(char *s, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strcmp(s, "pa\n"))
		return (pa(lst_a, lst_b, 0), 1);
	if (!ft_strcmp(s, "pb\n"))
		return (pb(lst_a, lst_b, 0), 1);
	if (!ft_strcmp(s, "ra\n"))
		return (ra(lst_a, 0, NULL), 1);
	if (!ft_strcmp(s, "rb\n"))
		return (rb(lst_b, 0, NULL), 1);
	if (!ft_strcmp(s, "rr\n"))
		return (rr(lst_a, lst_b, 0, NULL), 1);
	if (!ft_strcmp(s, "rra\n"))
		return (rra(lst_a, 0, NULL), 1);
	if (!ft_strcmp(s, "rrb\n"))
		return (rra(lst_b, 0, NULL), 1);
	if (!ft_strcmp(s, "rrr\n"))
		return (rrr(lst_a, lst_b, 0, NULL), 1);
	if (!ft_strcmp(s, "sa\n"))
		return (sa(lst_a, 0), 1);
	if (!ft_strcmp(s, "sb\n"))
		return (sb(lst_b, 0), 1);
	if (!ft_strcmp(s, "ss\n"))
		return (ss(lst_a, lst_b, 0), 1);
	return (0);
}

static void	instruction_error(char *s, t_list **lst_a, t_list **lst_b)
{
	free(s);
	ft_lstclear(lst_b);
	parse_error(lst_a);
}

void	reverse_push_swap(t_list **lst_a)
{
	char	*s;
	t_list	*lst_b;

	lst_b = NULL;
	s = get_next_line(0);
	while (s)
	{
		if (!check_instruction(s, lst_a, &lst_b))
			return (instruction_error(s, lst_a, &lst_b));
		s = (free(s), get_next_line(0));
	}
	if (s)
		free(s);
	if (!(*lst_a) || !is_sorted(*lst_a) || lst_b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_lstclear(lst_a);
	ft_lstclear(&lst_b);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	int		count;

	count = 0;
	lst = NULL;
	argv++;
	if (argc < 2)
		return (1);
	if ((**argv) == 0)
		return (parse_error(&lst));
	if (argc == 2 && argv)
		argv = ft_split(*argv, ' ');
	if (!argv)
		return (parse_error(&lst));
	if (!create_list(argv, &lst, argc))
		return (parse_error(&lst));
	reverse_push_swap(&lst);
}
