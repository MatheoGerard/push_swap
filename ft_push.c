/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:31:31 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/22 15:42:37 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	push(t_stack src, t_stack dest)
{
	int	len_minus1;

	if (src->current_len == 0)
	{
		printf("%s\n", "no element in src stack!!!");
		return ;
	}
	len_minus1 = dest -> current_len - 1;
	pushup_tmp(src);
	pushdown_tmp(dest);
	dest.nbrs[0] = src->tmp;
	dest.nbrs[len_minus1] = dest->tmp;
	src -> current_len -= 1;
	dest -> current_len += 1;
}

void	push_a(t_stack a, t_stack b)
{
	push(b, a);
}


void	push_b(t_stack a, t_stack b)
{
	push(a, b);
}


