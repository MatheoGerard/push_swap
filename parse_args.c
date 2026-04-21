/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:21:38 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/21 17:30:53 by mgerard          ###   ########.fr       */
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

t_stack	**ft_init(char **str_array)
{
	int	i;
	t_stack	*a;
	t_stack	*b;
	t_stack	**stacks_ab;

	i = 0;
	while (str_array[i])
		if (!ft_is_int(str_array[i++]))
		{
			a->nbrs = NULL;
			stacks_ab[0] = a;
			return (stacks_ab);
		}
	a->nbrs = (int *)malloc(i * sizeof(int));
	b->nbrs = (int *)ft_calloc(i, sizeof(int));
	if (a == NULL)
		return (NULL);
	a->current_len = i - 1;
	b->current_len = 0;
	stacks_ab[0] = a;
	stacks_ab[1] = b;
	return (stacks_ab);
}

void	ft_parse(char **argv, t_stack **stacks_ab)
{
	int	i;

	i = 0;
	argv++;
	stacks_ab = ft_init(argv);
	while (argv[i])
	{
		stacks_ab[0]->nbrs[i] = ft_atoi(argv[i]);
		i++;
	}
}
