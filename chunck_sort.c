/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:18:36 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/27 16:19:51 by mgerard          ###   ########.fr       */
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

	min = 0;
	i = 0;
	while (i < a->current_len - 1)
	{
		j = i + 1;
		while (j < a->current_len)
		{
			if (a->nbrs[min] > a->nbrs[j]) 
			{
				min = j;
			}
			j++;
		}
		a->index[min] = i;
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
		if (a->nbrs[i] > base_nb)
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
	greater = greater_nb_than_base(a, a->nbrs[0]);
	fork_size = ft_sqrt(a->current_len);
	while (a->current_len > 0)
	{
		base_nb = fork_size * j;
		if (fork_size < greater)
			limit = fork_size;
		else
			limit = greater;
		while (i < limit)
		{
			if (a->index[i] < base_nb)
			{
				push(a, b, 'b');
				i++;
			}
			else
			{
				rotate(a, b, 'a');
			}
		}
		greater = greater_nb_than_base(a, base_nb);
		i = 0;
		j++;
	}
}
/*
int	check_max_chunck(t_stack *a, int fork_size)
{

}
*/
