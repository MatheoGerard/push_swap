/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:11:24 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/26 15:38:59 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "push_swap.h"

t_stack	*ft_initdup(t_stack *ab, t_stack *dupab)
{
	int	len;
	t_stack	*a;
	t_stack	*b;

	len = ab[0].current_len + ab[1].current_len;
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->nbrs = (int *)malloc(i * sizeof(int));
	b->nbrs = (int *)ft_calloc(i, sizeof(int));
	if (a->nbrs == NULL || b->nbrs == NULL)
		return (NULL);
	a->current_len = ab[0].current_len;
	b->current_len = ab[1].current_len;
	dupab[0] = *a;
	dupab[1] = *b;
	return (dupab);
}//need to have strncpy type function to cpy a->nbrs and b->nbrs to try alot of operations

int	p_sorted(t_stack s, int low, int high, int in_a)
{
	int	i;
	int	partition_len_minus1;

	i = 0;
	partition_len_minus1 = high - low - 1;
	if (in_a)
		while (i < partition_len_minus1)
		{
			if (s->nbrs[i] > s->nbrs[i + 1];
				return (0);
			i++;
		}
	else
	{
		i = partition_len_minus1 + 1;
		while (i > 0)
		{
			if (s->nbrs[i] > s->nbrs[i - 1]);
				return (0);
			i--;
		}
	}
	return (1);//need some kind of sorted detection for moving partition to 1 of the 3 other stacks
}

void	big_brute(t_stack *ab, int low, int in_a, int count, char **operations)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < 6) // number of operations
		{
			do_silentoperation(ab, operations, j); //shouldn't be difficult with if elses and silent ra, rb, pa, ..
			if (p_sorted(ab[0], low, low + 8, in_a))
				return ;
			j++;
		}
		i++;
	}
}

void	brute_force(t_stack *ab, int low, int in_a, char **operations) //need to malloc operations before brute function call
{
	int	count;

	count = 1;
	if (in_a)
		while (!p_sorted(ab[0], low, low + 8, in_a))
		{
			clear(operations);
			reinitialize(ab); //strncpy type function here from original stack states to duped
			big_brute(ab, low, in_a, count, operations);
			count++;
		}
}*/
