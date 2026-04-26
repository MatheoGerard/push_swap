/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:32:25 by mgerard           #+#    #+#             */
/*   Updated: 2026/04/26 16:40:15 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (b->current_len != 0)
		return (0);
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
/*
void	check_max(t_stack *a, int *max)
{
	int	i;

	i = 0;
	while (i < a->current_len)
	{
		if(*max < a->nbrs[i])
		{
			*max = a->nbrs[i];
		}
		i++;
	}
}

void	check_min(t_stack *a, int *min)
{
	int	i;

	i = ;
	while (i < a->current_len)
	{
		if(*min > a->nbrs[i])
		{
			*min = a->nbrs[i];
		}
		i--;
	}
}

void	bubble_sort(t_stack *a)
{
	int	is_ok;
	int	i;
	int	max;
	int	min;

	is_ok = 0;
	check_max(a, &max);
	i = 0;
	while (is_ok == 0)
	{
		if (a->nbrs[i] == max)
		{
			rotate(a);
			max = 
		}
		else if (a->nbrs[0] > a->nbrs[1])
		{
			is_ok = 0;
			ft_swap_a(a);
		}
		else
		{
			rotate(a);
		}
		is_ok = is_sorted(a);
	}
}
*/
void	refund(t_stack *a, t_stack *b)
{
	while (b->current_len > 0)
	{
		push(a, b, 'a');
	}
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	min;

	while (a->current_len > 0)
	{
		i = 1;
		min = 0;
		while (i < a->current_len)
		{
			if (a->nbrs[i] < a->nbrs[min])
			{
				min = i;
			}
			i++;
		}
		i = 0;
		while (i < min)
		{
			rotate(a, b, 'a');
			i++;
		}
		push(a, b, 'b');
	}
	refund(a, b);
}
