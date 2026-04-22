/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:34 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/22 17:30:16 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_swap(t_stack *stack)
{
	if (stack->current_len == 1)
	{
		printf("%s\n", "not enough element in stack!!!");
		return ;
	}
	stack->tmp = stack->nbrs[0];
	stack->nbrs[0] = stack->nbrs[1];
	stack->nbrs[1] = stack->tmp;
}

void	ft_swap_a(t_stack *a)
{
	ft_swap(a);
}

void	ft_swap_b(t_stack *b)
{
	ft_swap(b);
}
