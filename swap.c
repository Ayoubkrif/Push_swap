/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:34:59 by aykrifa           #+#    #+#             */
/*   Updated: 2024/12/11 14:05:04 by aykrifa          ###   ########.fr       */
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
