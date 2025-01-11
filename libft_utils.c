/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:06:24 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/09 16:09:03 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src || dest > src + n)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n != 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}

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
