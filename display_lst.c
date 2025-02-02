/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:12:28 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/15 09:14:25 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d", lst->nbr);
		if (lst->next)
			ft_printf(" =>");
		lst = lst->next;
	}
	ft_printf("\n");
}

void	printlist_index(t_list *lst)
{
	if (!lst)
		ft_printf("empty!\n");
	while (lst)
	{
		ft_printf("%d", lst->index);
		if (lst->next)
			ft_printf(" =>");
		lst = lst->next;
	}
	ft_printf("\n");
}
