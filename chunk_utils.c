/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:12:15 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/15 14:13:38 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	tmp;

	tmp = 0;
	if (nb < 0)
		return (0);
	while (tmp <= nb)
	{
		if ((tmp * tmp) == nb || (tmp * tmp) > nb)
			return (tmp);
		tmp++;
	}
	return (0);
}

void	index_select(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->current_len)
	{
		a->index[i] = 0;
		j = 0;
		while (j < a->current_len)
		{
			if (a->nbrs[i] > a->nbrs[j])
				a->index[i] += 1;
			j++;
		}
		i++;
	}
}
