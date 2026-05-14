/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 06:46:25 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/14 21:10:23 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double_num(t_stack *a, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->current_len + 1)
	{
		j = i + 1;
		while (j < a->current_len)
		{
			if (a->nbrs[i] == a->nbrs[j])
				return (destroy_all(av, a, 0), 1);
			j++;
		}
		i++;
	}
	return (0);
}
