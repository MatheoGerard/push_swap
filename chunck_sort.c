/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:18:36 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/15 18:29:58 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_t_b(t_stack *a, int base_nb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < a->current_len)
	{
		if (a->index[i] < base_nb)
			count++;
		i++;
	}
	return (count);
}

int	check_range(int max, t_stack *b)
{
	int	i;

	i = 0;
	while (b->nbrs[i] != max)
		i++;
	return (i);
}

void	check_for_max(t_stack *a, t_stack *b, t_op_count *values, int is_bench)
{
	int	i;
	int	max;

	i = 0;
	while (b->current_len > 0)
	{
		i = 0;
		max = b->nbrs[0];
		while (i < b->current_len)
		{
			if (b->nbrs[i] > max)
				max = b->nbrs[i];
			i++;
		}
		values->in_stack = 'b';
		if (check_range(max, b) < (b->current_len / 2) + 1)
			while (b->nbrs[0] != max)
				rotate(a, values, is_bench);
		else
			while (b->nbrs[0] != max)
				rrotate(a, values, is_bench);
		values->in_stack = 'a';
		push(a, is_bench, values);
	}
}

void	chunk_sort_loop(int base_nb, int is_bench, t_stack *ab, t_op_count *val)
{
	if ((&ab[0])->index[0] < base_nb)
		pushfrom(ab, is_bench, val);
	else
		rotate(ab, val, is_bench);
}

void	chunck_divide(t_stack *ab, t_op_count *values, int is_bench)
{
	int	base_nb;
	int	limit;
	int	j;
	int	i;

	i = 0;
	j = 1;
	index_select(&ab[0]);
	while ((&ab[0])->current_len > 0)
	{
		base_nb = (ft_sqrt((&ab[0])->current_len)) * j;
		if (ft_sqrt((&ab[0])->current_len) <= greater_t_b(&ab[0], base_nb))
			limit = ft_sqrt((&ab[0])->current_len);
		else
			limit = greater_t_b(&ab[0], base_nb);
		while (i < limit)
		{
			if ((&ab[0])->index[0] < base_nb)
				i++;
			chunk_sort_loop(base_nb, is_bench, ab, values);
		}
		i = 0;
		j++;
	}
	check_for_max(ab, &ab[1], values, is_bench);
}
