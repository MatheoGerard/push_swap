/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:31:31 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/22 18:13:05 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	push(t_stack *src, t_stack *dest)
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
	src -> current_len -= 1;
	dest -> current_len += 1;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
}


void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
}


