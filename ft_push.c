/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:31:31 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/17 17:16:27 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing(t_stack *src, t_stack *dest)
{
	int	len;

	if (src->current_len == 0)
		return ;
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

void	push(t_stack *ab, int is_bench, t_op_count *values)
{
	pushing(&ab['b' - values->in_stack], &ab[values->in_stack - 'a']);
	if (is_bench)
	{
		if (values->in_stack == 'a')
			values->pb += 1;
		else
			values->pa += 1;
	}
	ft_printf(1, "p%c\n", values->in_stack);
}

void	pushfrom(t_stack *stacks_ab, int is_bench, t_op_count *values)
{
	if (values->in_stack == 'a')
	{
		values->in_stack = 'b';
		push(stacks_ab, is_bench, values);
		values->in_stack = 'a';
	}
	else
	{
		values->in_stack = 'a';
		push(stacks_ab, is_bench, values);
		values->in_stack = 'b';
	}
}
