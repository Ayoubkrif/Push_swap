/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:12:28 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/09 16:12:56 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_printlist(t_list *lst)
{
	while (lst)
	{
		printf("%d", lst->nbr);
		if (lst->next)
			printf(" =>");
		lst = lst->next;
	}
	printf("\n");
}

void	ft_printlist_index(t_list *lst)
{
	if (!lst)
		printf("empty!");
	while (lst)
	{
		printf("%d", lst->index);
		if (lst->next)
			printf(" =>");
		lst = lst->next;
	}
	printf("\n");
}

void	ft_printlist_decile(t_list *lst)
{
	while (lst)
	{
		printf("%d", lst->decile);
		if (lst->next)
			printf(" =>");
		lst = lst->next;
	}
	printf("\n");
}
