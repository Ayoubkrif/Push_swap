/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:34:59 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 15:06:38 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst_a, int mode)
{
	if (*lst_a && (*lst_a)->next)
		ft_swaplst(lst_a, *lst_a, (*lst_a)->next);
	if (mode)
		ft_printf("sa\n");
}

void	sb(t_list **lst_b, int mode)
{
	if (*lst_b && (*lst_b)->next)
		ft_swaplst(lst_b, *lst_b, (*lst_b)->next);
	if (mode)
		ft_printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b, int mode)
{
	if (*lst_a && (*lst_a)->next)
		ft_swaplst(lst_a, *lst_a, (*lst_a)->next);
	if (*lst_b && (*lst_b)->next)
		ft_swaplst(lst_b, *lst_b, (*lst_b)->next);
	if (mode)
		ft_printf("ss\n");
}
