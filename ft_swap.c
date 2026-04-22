/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:34 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/22 19:54:43 by mgerard          ###   ########.fr       */
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
	printf("sa\n");
}

void	ft_swap_b(t_stack *b)
{
	ft_swap(b);
	printf("sb\n");
}
