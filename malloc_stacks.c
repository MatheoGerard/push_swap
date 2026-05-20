/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:56:56 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/20 19:07:24 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	malloc_stacks(t_stack *ab, int i)
{
	ab[0].nbrs = (int *)malloc(i * sizeof(int));
	if (!ab[0].nbrs)
		return (0);
	ab[0].index = (int *)malloc(i * sizeof(int));
	if (!ab[0].index)
	{
		free(ab[0].nbrs);
		return (0);
	}
	ab[1].nbrs = (int *)malloc(i * sizeof(int));
	if (!ab[1].nbrs)
	{
		free(ab[0].nbrs);
		free(ab[0].index);
		return (0);
	}
	ab[1].index = (int *)malloc(i * sizeof(int));
	if (!ab[1].index)
	{
		free(ab[0].nbrs);
		free(ab[0].index);
		free(ab[1].nbrs);
		return (0);
	}
	return (1);
}
