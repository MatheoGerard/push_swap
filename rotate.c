/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:41:59 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 17:17:00 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushup_tmp(t_stack *stack)
{
	int	i;
	int	len_minus1;

	i = 0;
	len_minus1 = stack->current_len - 1;
	if (len_minus1 == -1)
		return ;
	stack->tmp = stack->nbrs[0];
	stack->tmpi = stack->index[0];
	while (i < len_minus1)
	{
		stack->nbrs[i] = stack->nbrs[i + 1];
		stack->index[i] = stack->index[i + 1];
		i++;
	}
}

void	pushdown_tmp(t_stack *stack)
{
	int	len_minus1;

	len_minus1 = stack->current_len - 1;
	if (len_minus1 == -1)
		return ;
	stack->tmp = stack->nbrs[len_minus1];
	stack->tmpi = stack->index[len_minus1];
	while (len_minus1 > 0)
	{
		stack->nbrs[len_minus1] = stack->nbrs[len_minus1 - 1];
		stack->index[len_minus1] = stack->index[len_minus1 - 1];
		len_minus1--;
	}
}

void	rotate(t_stack *stacks_ab, t_op_count *values, int is_bench)
{
	int		end;
	t_stack	*stack;

	stack = &stacks_ab[values->in_stack - 'a'];
	if (stack->current_len <= 1)
		return ;
	end = stack->current_len - 1;
	pushup_tmp(stack);
	stack->nbrs[end] = stack->tmp;
	stack->index[end] = stack->tmpi;
	if (is_bench)
	{
		if (values->in_stack == 'a')
			values->ra += 1;
		else
			values->rb += 1;
	}
	ft_printf(1, "r%c\n", values->in_stack);
}

void	rrotate(t_stack *stacks_ab, t_op_count *values, int is_bench)
{
	t_stack	*stack;

	stack = &stacks_ab[values->in_stack - 'a'];
	if (stack->current_len <= 1)
		return ;
	pushdown_tmp(stack);
	stack->nbrs[0] = stack->tmp;
	stack->index[0] = stack->tmpi;
	if (is_bench)
	{
		if (values->in_stack == 'a')
			values->rra += 1;
		else
			values->rrb += 1;
	}
	ft_printf(1, "rr%c\n", values->in_stack);
}
