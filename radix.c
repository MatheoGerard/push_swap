/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:55:12 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 16:04:16 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *ab, t_op_count *values, int is_bench)
{
	int	stack_a_len;
	int	i;
	int	j;

	i = 0;
	index_select(ab);
	while (!sorted(ab))
	{
		stack_a_len = ab->current_len;
		j = 0;
		while (j < stack_a_len)
		{
			if (sorted(ab))
				break ;
			else if (((ab->index[0] >> i) & 1) == 1)
				rotate(ab, values, is_bench);
			else
				pushfrom(ab, is_bench, values);
			j++;
		}
		while (ab[1].current_len)
			push(ab, is_bench, values);
		i++;
	}
}
