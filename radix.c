/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:55:12 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/16 21:11:30 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_end_sort(t_stack *ab)
{
	int	i;

	i = ab->current_len - 1;
	while (i < ab[1].current_len - 1 &&
			ab->index[i] == i + ab[1].current_len - 1)
		i--;
	return (ab->current_len - 1 - i);
}

int	index_already_sort(t_stack *ab)
{
	int	i;

	i = ab->current_len - 1;
	while (ab->index[i] == i)
		i--;
	return (i);
}

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
			if (((ab->index[0] >> i) & 1) == 1)
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
