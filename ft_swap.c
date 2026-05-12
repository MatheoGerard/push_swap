/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:34 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/12 22:20:21 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_swaop(t_stack *stack)
{
	if (stack->current_len == 1)
	{
		printf("%s\n", "not enough element in stack!!!");
		return ;
	}
	stack->tmp = stack->nbrs[0];
	stack->nbrs[0] = stack->nbrs[1];
	stack->nbrs[1] = stack->tmp;
	stack->tmpi = stack->index[0];
	stack->index[0] = stack->index[1];
	stack->index[1] = stack->tmpi;
}

void	ft_swap(t_stack *stacks_ab, char in_stack, int is_bench, t_op_count *values)
{
	if (is_bench)
	{
		if (in_stack == 'a')
		{
			ft_swaop(&stacks_ab[0]);
			values->sa += 1;
		}
		else
		{
			ft_swaop(&stacks_ab[1]);
			values->sb += 1;
		}
	}
	else
		printf("s%c\n", in_stack);
}

