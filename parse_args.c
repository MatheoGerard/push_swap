/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:21:38 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/27 14:50:45 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_int(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

t_stack	*ft_init(char **str_array, t_stack *stacks_ab)
{
	int	i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	while (str_array[i])
		if (!ft_is_int(str_array[i++]))
		{
			stacks_ab[0] = *a;
			return (stacks_ab);
		}
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->nbrs = (int *)malloc(i * sizeof(int));
	b->nbrs = (int *)malloc(i * sizeof(int));
	a->index = (int *)malloc(i * sizeof(int));
	b->index = (int *)malloc(i * sizeof(int));
	if (a->nbrs == NULL || b->nbrs == NULL)
		return (NULL);
	a->current_len = i;
	b->current_len = 0;
	stacks_ab[0] = *a;
	stacks_ab[1] = *b;
	return (stacks_ab);
}

void	ft_parse(char **argv, t_stack *stacks_ab)
{
	int	i;

	i = 0;
	argv++;
	stacks_ab = ft_init(argv, stacks_ab);
	while (argv[i])
	{
		stacks_ab[0].nbrs[i] = ft_atoi(argv[i]);
		stacks_ab[0].index[i] = i;
		i++;
	}
}
