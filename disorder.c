/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 01:50:54 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/13 02:31:49 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_stack *a)
{
	int	i;
	int	j;
	float	total_pairs;
	float	mistakes;

	i = 0;
	mistakes = 0.0f;
	total_pairs = 0.0f;
	while (i < a->current_len)
	{
		j = i + 1;
		while (j < a->current_len - 1)
		{
			total_pairs += 1.0f;
			if (a->nbrs[i] > a->nbrs[j])
				mistakes += 1.0f;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
