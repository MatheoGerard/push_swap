/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:31:31 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/27 10:40:25 by nlovius          ###   ########.fr       */
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

void	push(t_stack *a, t_stack *b, char in_stack)
{
	if (in_stack == 'a')
		pushing(b, a);
	else
		pushing(a, b);
	printf("p%c\n", in_stack);
}

void	pushfrom(t_stack *a, t_stack *b, char in_stack)
{
	if (in_stack == 'a')
		in_stack = 'b';
	else
		in_stack = 'a';
	push(a, b, in_stack);
}
