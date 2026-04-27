/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:34:34 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/28 00:33:36 by mgerard          ###   ########.fr       */
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

void	ft_swap(t_stack *a, t_stack *b, char in_stack)
{
	if (in_stack == 'a')
		ft_swaop(a);
	else
		ft_swaop(a);
	printf("s%c\n", in_stack);
}

