/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:06:24 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 13:16:48 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_swap(void *data1, void *data2, int size)
{
	void	*temp;

	temp = malloc(size);
	if (temp == NULL)
		return ;
	ft_memmove(temp, data1, size);
	ft_memmove(data1, data2, size);
	ft_memmove(data2, temp, size);
	free(temp);
}
