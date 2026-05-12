/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:53:28 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/12 17:39:03 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *argv, char *flag)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != flag[i])
			return (0);
		i++;
	}
	return (1);
}

void	flag_detect(char **argv, int mode_return[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	mode_return[0] = -1;
	mode_return[1] = -1;
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
		i++;
	}
}

void	do_simple(char** argv, t_stack *stacks_ab, int is_bench)
{
	if (is_bench)
	{
		//bench();
		ft_parse(argv, stacks_ab, 1, 1);
	}
	else
		ft_parse(argv, stacks_ab, 1, 0);
	selection_sort(&stacks_ab[0], &stacks_ab[1]);
}

void	do_medium(char** argv, t_stack *stacks_ab, int is_bench)
{
	if (is_bench)
	{
		//bench();
		ft_parse(argv, stacks_ab, 1, 1);
	}
	else
		ft_parse(argv, stacks_ab, 1, 0);
	chunck_divide(&stacks_ab[0], &stacks_ab[1]);
}

void	flag_validation(char **argv, int ac, t_stack *stacks_ab)
{
	int	flag_find[2];
	int	is_bench;

	flag_detect(argv, flag_find);
	is_bench = 0;
//	if (flag_find[0] == 0 && flag_find[1] != 0)
//		return (do_ERROR());
//	if (flag_find[0] == flag_find[1])
//		return (ERROR());
	if (flag_find[0] == 1 || flag_find[1] == 1)
		is_bench = 1;//???
	if (flag_find[0] == 2 || flag_find[1] == 2)
		do_simple(argv, stacks_ab, is_bench);//???
	if (flag_find[0] == 3 || flag_find[1] == 3)
		do_medium(argv, stacks_ab, is_bench);//???
/*	if (flag_find[0] == 4 || flag_find[1] == 4)
		complex(is_bench);//???
	if (flag_find[0] == 5 || flag_find[1] == 5)
		adaptive(is_bench);//???
*/
}






