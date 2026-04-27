/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:18:36 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/27 17:53:04 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	tmp;
	int	is_sqrt_nb;

	tmp = 0;
	if (nb < 0)
	{
		return (0);
	}
	is_sqrt_nb = 0;
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
	int	min;
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

void	chunck_divide(t_stack *a, t_stack *b)
{
	int	base_nb;
	int	fork_size;
	int	i;
	int	greater;
	int	limit;
	int	j;

	i = 0;
	j = 1;
	index_select(a);
	fork_size = ft_sqrt(a->current_len);
	while (a->current_len > 0)
	{
		base_nb = fork_size * j;
		greater = greater_nb_than_base(a, base_nb);
		if (fork_size <= greater)
			limit = fork_size;
		else
			limit = greater;
		while (i < limit)
		{
			if (a->index[0] < base_nb)
			{
				push(a, b, 'b');
				i++;
			}
			else
			{
				rotate(a, b, 'a');
			}
		}
		i = 0;
		j++;
	}
}
/*
int	check_max_chunck(t_stack *a, int fork_size)
{

}
*/
