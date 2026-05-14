/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:44:16 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/28 13:40:02 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partitions(t_stacks *ab, char in_stack, int low, int high)
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
			pushfrom(&ab[0], &ab[1], in_stack);
		else
			rotate(&ab[0], &ab[1], in_stack);
	}
	stack = &ab[0];
	while (i < stack->current_len)
	{
		stack->index[i] = i + (&ab[1])->current_len;
		i++;
	}
	stack = &ab[1];
	i = 0;
	while (i < stack->current_len)
	{
		stack->index[i] = stack->current_len - i;
		i++;
	}
	return (find_index(a, b, p_val));
}
