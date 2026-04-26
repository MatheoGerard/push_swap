/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:22:29 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/26 17:30:59 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_in_history(t_stack *a, t_stack *b, t_stack *pi, char in_stack)
{
	int	i;

	i = 0;
	if (in_stack == 'a')
	{
		while (i < a->current_len - 1)
		{
			if (!is_in_history(pi, a, b, in_stack, i))
				return (0);
			i++;
		}
	}
	else
	{
		while (i < b->current_len - 1)
		{
			if (!is_in_history(pi, a, b, in_stack, i))
				return (0);
			i++;
		}
	}
	return (1);
}
