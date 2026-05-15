/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:44:16 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/15 21:13:37 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_index(t_stack *ab, int pivot_index)
{
	(void)ab;
	return (pivot_index);
}

int	partitions(t_stack *ab, int low, int high, t_op_count *values, int is_bench)
{
	int	p_val;
	int	pi;
	int	i;
	t_stack	*stack;
	
	(void)low;
	stack = &ab[values->in_stack - 'a'];
	p_val = stack->nbrs[high];
	pi = stack->index[high];
	i = 0;
	while (stack->index[0] != pi)
	{
		if ((values->in_stack == 'a' && stack->nbrs[0] < p_val) ||
				(values->in_stack == 'b' && stack->nbrs[0] > p_val))
			pushfrom(ab, is_bench, values);
		else
			rotate(ab, values, is_bench);
	}
	stack = &ab[0];
	while (i < stack->current_len)
	{
		stack->index[i] = i + (&ab[1])->current_len;
		if (p_val == stack->nbrs[i])
			pi = stack->index[i];
		//printf("%d --> %d\n", stack->index[i], stack->nbrs[i]);
		i++;
	}
	stack = &ab[1];
	i = 0;
	while (i < stack->current_len)
	{
		stack->index[i] = stack->current_len - i - 1;
		if (p_val == stack->nbrs[i])
			pi = stack->index[i];
		//printf("%d --> %d\n", stack->index[i], stack->nbrs[i]);
		i++;
	}
	return (pi);
}

void	quick_sortish(t_stack *stacks_ab, t_op_count *values, int is_bench)
{
	int	pi;

	pi = stacks_ab->current_len - 1;
	while (1)
	{
		pi = partitions(stacks_ab, 0, stacks_ab->current_len - 1, values, is_bench);
		values->in_stack = 'b';
		pi = partitions(stacks_ab, 0, 0, values, is_bench);
		pi--;
		values->in_stack = 'a';
	}
}
