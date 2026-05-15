/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:44:16 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/15 15:06:29 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_index(t_stack *ab, int pivot_index)
{
	return (pivot_index);
}

int	partitions(t_stack *ab, char in_stack, int low, int high, t_op_count *values, int is_bench)
{
	int	p_val;
	int	pi;
	int	i;
	t_stack	*stack;
	
	stack = &ab[in_stack - 'a'];
	p_val = stack->nbrs[high];
	pi = stack->index[high];
	i = 0;
	while (stack->index[0] != pi)
	{
		if (in_stack == 'a' && stack->nbrs[0] < p_val ||
				in_stack == 'b' && stack->nbrs[0] > p_val)
			pushfrom(ab, in_stack, is_bench, values);
		else
			rotate(ab, in_stack, values, is_bench);
	}
	stack = &ab[0];
	while (i < stack->current_len)
	{
		stack->index[i] = i + (&ab[1])->current_len;
		printf("%d --> %d\n", stack->index[i], stack->nbrs[i]);
		i++;
	}
	stack = &ab[1];
	i = 0;
	while (i < stack->current_len)
	{
		stack->index[i] = stack->current_len - i;
		printf("%d --> %d\n", stack->index[i], stack->nbrs[i]);
		i++;
	}
	return (find_index(ab, p_val));
}
