/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:41:59 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/14 18:04:10 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	rotate(t_stack *stacks_ab, char stack_in, t_op_count *values, int is_bench)
{
	int	end;
	t_stack	*stack;

	stack = &stacks_ab[stack_in - 'a'];//????
	if (stack->current_len <= 1)
		//return ((void)printf("%s\n", "1 or no element in stack!!!"));
		return ;
	end = stack->current_len - 1;
	pushup_tmp(stack);
	stack->nbrs[end] = stack->tmp;
	stack->index[end] = stack->tmpi;
	if (is_bench)
	{
		if (stack_in == 'a')
			values->ra += 1;
		else
			values->rb += 1;
	}
	printf("r%c\n", stack_in);
}

void	rrotate(t_stack *stacks_ab, char stack_in, t_op_count *values, int is_bench)
{
	t_stack	*stack;

	stack = &stacks_ab[stack_in - 'a'];//????
	if (stack->current_len <= 1)
		//return ((void)printf("%s\n", "1 or no element in stack!!!"));
		return ;
	pushdown_tmp(stack);
	stack->nbrs[0] = stack->tmp;
	stack->index[0] = stack->tmpi;
	if (is_bench)
	{
		if (stack_in == 'a')
			values->rra += 1;
		else
			values->rrb += 1;
	}
	printf("rr%c\n", stack_in);
}
