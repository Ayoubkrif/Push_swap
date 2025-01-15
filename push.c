/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:30:39 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 13:05:55 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b, int mode)
{
	t_list	*temp;

	temp = (*lst_b)->next;
	if (temp)
		temp->prev = NULL;
	ft_lstadd_front(lst_a, (*lst_b));
	*lst_b = temp;
	if (mode)
		ft_printf("pa\n");
}

void	pb(t_list	**lst_a, t_list	**lst_b, int mode)
{
	t_list	*temp;

	temp = (*lst_a)->next;
	if (temp)
		temp->prev = NULL;
	ft_lstadd_front(lst_b, (*lst_a));
	*lst_a = temp;
	if (mode)
		ft_printf("pb\n");
}
