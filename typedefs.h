/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:01:57 by aykrifa           #+#    #+#             */
/*   Updated: 2025/01/14 14:03:46 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_cost
{
	int	ra;
	int	rb;
}t_cost;

typedef struct s_list
{
	int				nbr;
	int				index;
	int				pos;
	int				total_cost;
	t_cost			cost;
	int				info;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

typedef struct s_nbr
{
	int	nbr;
	int	index;
	int	rotate;
	int	info;
}t_nbr;

#endif
