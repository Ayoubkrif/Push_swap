/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:34:59 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/07 09:27:39 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	lst_swap(t_list **lst, int *count)
{
	if (ft_lstsize(*lst) == 1)
		return ;
	ft_swap(&(*lst)->nbr, &(*lst)->next->nbr);
	*count += 1;
}

void	sa(t_list *lst_a, t_list *lst_b, int *count)
{
	printf("sa\n");
}

void	sb(t_list *lst_a, t_list *lst_b, int *count)
{
	printf("sb\n");
}

void	ss(t_list *lst_a, t_list *lst_b, int *count)
{
	printf("ss\n");
}
