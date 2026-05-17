/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:32:25 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/17 13:19:17 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->current_len - 1)
	{
		if (a->nbrs[i] > a->nbrs[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	refund(t_stack *ab, int is_bench, t_op_count *values)
{
	while ((&ab[1])->current_len > 0)
	{
		push(ab, is_bench, values);
	}
}

void	push_min(t_stack *ab, int is_bench, t_op_count *values)
{
	if (!sorted(&ab[0]))
		pushfrom(ab, is_bench, values);
}

void	selection_sort(t_stack *ab, int is_bench, t_op_count *values)
{
	int	i;
	int	min;

	while (!sorted(&ab[0]))
	{
		i = 1;
		min = 0;
		while (!sorted(&ab[0]) && i < (&ab[0])->current_len)
		{
			if ((&ab[0])->nbrs[i] < (&ab[0])->nbrs[min])
				min = i;
			i++;
		}
		i = 0;
		while (!sorted(&ab[0]) && i < min && i < (&ab[0])->current_len - min)
		{
			if ((&ab[0])->current_len - min < min)
				rrotate(ab, values, is_bench);
			else
				rotate(ab, values, is_bench);
			i++;
		}
		push_min(ab, is_bench, values);
	}
	refund(ab, is_bench, values);
}
