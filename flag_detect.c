/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 03:53:28 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/13 07:37:47 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

t_op_count	*init_values(int is_adpt, t_stack *stacks_ab)
{
	t_op_count	*values;

	values = (t_op_count *)malloc(sizeof(t_op_count));
	if (!values)
		return (NULL);
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

void	do_simple(char** argv, t_stack *stacks_ab, int is_bench, int is_adpt)
{
	t_op_count	*values;

	if (!is_adpt)
	{
		if (is_bench)
		{
			if (!ft_parse(argv, stacks_ab, 1, 1))
				return ;
		}
		else
			if(!ft_parse(argv, stacks_ab, 1, 0))
				return ;
	}
	values = init_values(is_adpt, stacks_ab);
	if (!values)
		return ;
	selection_sort(stacks_ab, is_bench, values);
	if (is_adpt)
		do_print(values, is_bench, "Adaptive / O(n²)");
	else
		do_print(values, is_bench, "Simple / O(n²)");
}

void	do_medium(char** argv, t_stack *stacks_ab, int is_bench, int is_adpt)
{
	t_op_count	*values;

	if (!is_adpt)
	{
		if (is_bench)
		{
			if (!ft_parse(argv, stacks_ab, 1, 1))
				return ;
		}
		else
			if (!ft_parse(argv, stacks_ab, 1, 0))
				return ;
	}
	values = init_values(is_adpt, stacks_ab);
	chunck_divide(stacks_ab, values, is_bench);
	if (is_adpt)
		do_print(values, is_bench, "Adaptive / O(n√n)");
	else
		do_print(values, is_bench, "Medium / O(n√n)");
}

void	do_adaptive(char **argv, t_stack *stacks_ab, int is_bench, int *flag_find)
{
	float	disorder_value;

	if (flag_find[0] == 0 && flag_find[1] == 0)
		ft_parse(argv, stacks_ab, 0, 0);
	else if (is_bench && (flag_find[1] == 5 || flag_find[0] == 5))
		ft_parse(argv, stacks_ab, 1, 1);
	else
		ft_parse(argv, stacks_ab, 1, 0);
	disorder_value = disorder(stacks_ab);
	if (disorder_value <= .2f)
		do_simple(argv, stacks_ab, is_bench, 1);
	else if (disorder_value <= .5f)
		do_medium(argv, stacks_ab, is_bench, 1);
	else
		printf("your bigger dumbass\n");
}

void	flag_validation(char **argv, int ac, t_stack *stacks_ab)
{
	int	flag_find[2];
	int	is_bench;

	is_bench = 0;
	flag_detect(argv, flag_find);
	if (flag_find[0] == -1 || flag_find[1] == -1)
		return (ft_putstr_fd("Error\n", 2));
	if (flag_find[0] == 1 || flag_find[1] == 1)
		is_bench = 1;
	if (flag_find[0] == 2 || flag_find[1] == 2)
		do_simple(argv, stacks_ab, is_bench, 0);
	else if (flag_find[0] == 3 || flag_find[1] == 3)
		do_medium(argv, stacks_ab, is_bench, 0);
//	if (flag_find[0] == 4 || flag_find[1] == 4)
//		complex(is_bench);//???
	else
		do_adaptive(argv, stacks_ab, is_bench, flag_find);
}






