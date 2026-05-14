/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:18:36 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/14 10:26:18 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	tmp;

	tmp = 0;
	if (nb < 0)
	{
		return (0);
	}
	while (tmp <= nb)
	{
		if ((tmp * tmp) == nb || (tmp * tmp) > nb)
		{
			return (tmp);
		}
		//else if ((tmp *tmp) > nb)
		//{
		//	return (tmp - 1);
		//}
		tmp++;
	}
	return (0);
}

void	index_select(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->current_len)
	{
		a->index[i] = 0;
		j = 0;
		while (j < a->current_len)
		{
			if (a->nbrs[i] > a->nbrs[j]) 
			{
				a->index[i] += 1;
			}
			j++;
		}
		i++;
	}
}

int	greater_nb_than_base(t_stack *a, int base_nb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < a->current_len)
	{
		if (a->index[i] < base_nb)
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	check_range(int max, t_stack *b)
{
	int	i;

	i = 0;
	while (b->nbrs[i] != max)
	{
		i++;
	}
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
		if (check_range(max, b) < (b->current_len / 2) + 1)
		{
			while (b->nbrs[0] != max)
			{
				rotate(a, 'b', values, is_bench);
			}
		}
		else
		{
			while (b->nbrs[0] != max)
				rrotate(a, 'b', values, is_bench);
		}
		push(a, 'a', is_bench, values);
	}
}

void	chunck_divide(t_stack *ab, t_op_count *values, int is_bench)
{
	int	base_nb;
	int	fork_size;
	int	i;
	int	greater;
	int	limit;
	int	j;

	i = 0;
	j = 1;
	index_select(&ab[0]);
	fork_size = ft_sqrt((&ab[0])->current_len);
	while ((&ab[0])->current_len > 0)
	{
		base_nb = fork_size * j;
		greater = greater_nb_than_base(&ab[0], base_nb);
		if (fork_size <= greater)
			limit = fork_size;
		else
			limit = greater;
		while (i < limit)
		{
			if ((&ab[0])->index[0] < base_nb)
			{
				push(ab, 'b', is_bench, values);
				i++;
			}
			else
				rotate(ab, 'a', values, is_bench);
		}
		i = 0;
		j++;
	}
	check_for_max(ab, &ab[1], values, is_bench);
}


/*
int	check_max_chunck(t_stack *a, int fork_size)
{

}
*/
