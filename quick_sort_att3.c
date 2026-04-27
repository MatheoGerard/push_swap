/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_att3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:44:16 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/27 08:42:38 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "push_swap.h"

int	get_average_partition(t_stack s, int low, int high

t_stack	*init_pivot_history(t_stack *a)
{
	t_stack	*pi_history;
	
	pi_history = (t_stack *)malloc(sizeof(t_stack));
	if (pi_history == NULL)
		return (NULL);
	pi_history->current_len = 0;
	pi_history->nbrs = (int *)malloc(a->current_len * sizeof(int));
	if (pi_history->nbrs == NULL)
		return (NULL);
	return (pi_history);
}

void	add_pivot_to_history(t_stack *pi_history, t_stack *a, t_stack *b, char in_stack)
{
	if (in_stack == 'a')
		pi_history->nbrs[pi_history->current_len] = a->nbrs[0];
	else
		pi_history->nbrs[pi_history->current_len] = b->nbrs[0];
	pi_history->current_len += 1;
}

int	is_in_history(t_stack *pi_history, t_stack *a, t_stack *b, char a_or_b, int j)
{
	int	i;

	i = 0;
	while (i < pi_history->current_len)
	{
		if (a_or_b == 'a' && pi_history->nbrs[i] == a->nbrs[j])
			return (1);
		if (a_or_b == 'b' && pi_history->nbrs[i] == b->nbrs[j])
			return (1);
		i++;
	}
	return (0);
}

int	partition(t_stack *a, t_stack *b, t_stack *pi, char a_or_b, int *range)//need ranges
{
	int	i;

	i = 0;
	while (is_in_history(pi, a, b, a_or_b, 0))
	{
		rotate(a, b, a_or_b);
		i++;
	}
	if (!is_in_history(pi, a, b, a_or_b, 0))
	{
		add_pivot_to_history(pi, a, b, a_or_b);
		rotate(a, b, a_or_b);
		i++;
	}
	while ((a_or_b == 'a' && a->nbrs[0] != pi->nbrs[pi->current_len - 1])
			|| (a_or_b == 'b' && b->nbrs[0] != pi->nbrs[pi->current_len - 1]))
	{
		if ((a_or_b == 'a' && a->nbrs[0] < pi->nbrs[pi->current_len - 1])
				|| (a_or_b == 'b' && b->nbrs[0] > pi->nbrs[pi->current_len - 1]))
			push(a, b, a_or_b);
		else
			rotate(a, b, a_or_b);
		i++;
	}
	return (i);
}

void	quicksort(t_stack *a, t_stack *b, t_stack *pi, char in_stack)
{
	int	p;

	p = partition(a, b, pi, in_stack);
	if (in_stack == 'a')
		in_stack = 'b';
	else
		in_stack = 'a';
	if (!is_sorted(a, b))
	{
		if (!all_in_history(a, b, pi, in_stack))
			quicksort(a, b, pi, in_stack);
		if (in_stack == 'a')
			in_stack = 'b';
		else
			in_stack = 'a';
		if (!all_in_history(a, b, pi, in_stack))
			quicksort(a, b, pi, in_stack);
	}
		

}
*/
