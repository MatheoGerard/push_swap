/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:41:59 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/22 18:00:38 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushup_tmp(t_stack *stack)
{
	int	i;
	int	len_minus1;

	i = 0;
	len_minus1 = stack->current_len - 1;
	stack->tmp = stack->nbrs[0];
	while (i < len_minus1)
	{
		stack->nbrs[i] = stack->nbrs[i + 1];
		i++;
	}
}

void	pushdown_tmp(t_stack *stack)
{
	int	len_minus1;

	len_minus1 = stack->current_len - 1;
	stack->tmp = stack->nbrs[len_minus1];
	while (len_minus1 > 0)
	{
		stack->nbrs[len_minus1] = stack->nbrs[len_minus1 - 1];
		len_minus1--;
	}
}

void	rotate(t_stack *stack)
{
	int	end;

	if (stack->current_len <= 1)
	{
		printf("%s\n", "1 or no element in stack!!!");
	}
	end = stack->current_len - 1;
	pushup_tmp(stack);
	stack->nbrs[end] = stack->tmp;
}

void	rrotate(t_stack *stack)
{
	if (stack->current_len <= 1)
	{
		printf("%s\n", "1 or no element in stack!!!");
	}
	pushdown_tmp(stack);
	stack->nbrs[0] = stack->tmp;
}
