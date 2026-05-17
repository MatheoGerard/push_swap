/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:34 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/17 17:16:38 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swaop(t_stack *stack)
{
	if (stack->current_len == 1)
		return ;
	stack->tmp = stack->nbrs[0];
	stack->nbrs[0] = stack->nbrs[1];
	stack->nbrs[1] = stack->tmp;
	stack->tmpi = stack->index[0];
	stack->index[0] = stack->index[1];
	stack->index[1] = stack->tmpi;
}

void	ft_swap(t_stack *stacks_ab, int is_bench, t_op_count *values)
{
	if (is_bench)
	{
		if (values->in_stack == 'a')
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
	ft_printf(1, "s%c\n", values->in_stack);
}
