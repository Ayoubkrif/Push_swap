/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:39:12 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 10:32:45 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_unique(t_list *c1)
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

static int	is_number(char *str)
{
	if (!(ft_isdigit(*str) || *str == '+' || *str == '-'))
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	parse_error(t_list **lst)
{
	if (*lst)
		ft_lstclear(lst);
	write(2, "Error\n", 6);
	return (1);
}

static int	free_and_exit(int ret_val, int ac, char **arg)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (arg[i])
			free(arg[i++]);
		free(arg);
	}
	return (ret_val);
}

int	create_list(char **arg, t_list **lst, int ac)
{
	t_list	*node;
	int		i;
	long	nb;

	i = 0;
	while (arg[i])
	{
		if (!is_number(arg[i]))
			return (free_and_exit(0, ac, arg));
		nb = ft_atol(arg[i]);
		node = ft_lstnew((int)nb);
		if (!node || nb < -2147483648 || nb > 2147483647)
			return (free_and_exit(0, ac, arg));
		ft_lstadd_back(lst, node);
		i++;
	}
	if (!is_unique(*lst))
		return (free_and_exit(0, ac, arg));
	return (free_and_exit(1, ac, arg));
}
