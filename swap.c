/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:34:59 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 14:10:36 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst_a, int *count)
{
	ft_swaplst(lst_a, *lst_a, (*lst_a)->next);
	*count += 1;
	printf("sa\n");
}

void	sb(t_list **lst_b, int *count)
{
	ft_swaplst(lst_b, *lst_b, (*lst_b)->next);
	*count += 1;
	printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b, int *count)
{
	ft_swaplst(lst_a, *lst_a, (*lst_a)->next);
	ft_swaplst(lst_b, *lst_b, (*lst_b)->next);
	*count += 1;
	printf("ss\n");
}
