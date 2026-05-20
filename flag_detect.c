/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:53:28 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/20 17:37:33 by nlovius          ###   ########.fr       */
/*   Updated: 2026/05/15 16:39:39 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *argv, char *flag)
{
	int	i;

	if (argv == NULL)
		return (0);
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != flag[i])
			return (0);
		i++;
	}
	return (1);
}

int	init_mode_return_and_i(int mode_return[])
{
	mode_return[0] = -1;
	mode_return[1] = -1;
	return (1);
}

void	flag_detect(char **argv, int mode_return[])
{
	int	i;
	int	j;

	j = 0;
	i = init_mode_return_and_i(mode_return);
	if (!argv[i])
		return ;
	while (i < 3)
	{
		if (ft_is_int(argv[i]))
			mode_return[j++] = 0;
		else if (ft_strcmp(argv[i], "--bench"))
			mode_return[j++] = 1;
		else if (ft_strcmp(argv[i], "--simple"))
			mode_return[j++] = 2;
		else if (ft_strcmp(argv[i], "--medium"))
			mode_return[j++] = 3;
		else if (ft_strcmp(argv[i], "--complex"))
			mode_return[j++] = 4;
		else if (ft_strcmp(argv[i], "--adaptive"))
			mode_return[j++] = 5;
		else if (argv[i] == NULL)
			mode_return[j++] = -2;
		i++;
	}
}

void	*init_values(t_stack *stacks_ab, t_op_count *values)
{
	values->in_stack = 'a';
	values->disorder_val = disorder(stacks_ab);
	values->pa = 0;
	values->pb = 0;
	values->ra = 0;
	values->rb = 0;
	values->rr = 0;
	values->rra = 0;
	values->rrb = 0;
	values->rrr = 0;
	values->sa = 0;
	values->sb = 0;
	values->ss = 0;
	return (values);
}
