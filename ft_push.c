/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:31:31 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/13 09:37:46 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	pushing(t_stack *src, t_stack *dest)
{
	int	len;

	if (src->current_len == 0)
	{
		printf("%s\n", "no element in src stack!!!");
		return ;
	}
	len = dest -> current_len;
	pushup_tmp(src);
	pushdown_tmp(dest);
	dest->nbrs[len] = dest->tmp;
	dest->nbrs[0] = src->tmp;
	dest->index[len] = dest->tmpi;
	dest->index[0] = src->tmpi;
	src -> current_len -= 1;
	dest -> current_len += 1;
}

void	push(t_stack *stacks_ab, char in_stack, int is_bench, t_op_count *values)
{
	pushing(&stacks_ab['b' - in_stack], &stacks_ab[in_stack - 'a']);
	if (is_bench)
	{
		if (in_stack == 'a')
			values->pb += 1;
		else
			values->pa += 1;
	}
	printf("p%c\n", in_stack);
}

void	pushfrom(t_stack *stacks_ab, char in_stack, int is_bench, t_op_count *values)
{
	if (in_stack == 'a')
		in_stack = 'b';
	else
		in_stack = 'a';
	push(stacks_ab, in_stack, is_bench, values);
}
