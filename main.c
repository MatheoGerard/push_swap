/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:33:34 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/20 18:53:04 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_all(char **args, t_stack *stacks_ab, int crash)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		free(args[i]);
		i++;
	}
	if (args)
		free(args);
	args = NULL;
	if (!crash)
	{
		free((&stacks_ab[1])->index);
		free((&stacks_ab[0])->index);
		free((&stacks_ab[0])->nbrs);
		free((&stacks_ab[1])->nbrs);
	}
}

int	main(int ac, char **av)
{
	t_stack	stacks_ab[2];
	char	**args;
	int		crash;

	args = to_join_to_split(av);
	crash = flag_validation(ac, args, stacks_ab);
	destroy_all(args, stacks_ab, crash);
}
