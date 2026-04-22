/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:33:34 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/22 20:39:23 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	stacks_ab[2];
	t_stack	*a;
	t_stack	*b;

	ft_parse(av, stacks_ab);
	a = &stacks_ab[0];
	b = &stacks_ab[1];

	printf("|||||||STACK_A||||||\n");
	int i = 0;
	while (i < a->current_len)
	{
		printf("%d\n", a->nbrs[i]);
		i++;
	}
	printf("|||||||BECOMES||||||\n");
	//ft_swap(a);
	//bubble_sort(a);
	selection_sort(a, b);
	i = 0;
	printf("|||||||STACK_A||||||\n");
	while (i < a->current_len)
	{
		printf("%d\n", a->nbrs[i]);
		i++;
	}
	/*
	i = 0;
	printf("|||||||STACK_B||||||\n");
	while (i < b->current_len)
	{
		printf("%d\n", b->nbrs[i]);
		i++;
	}
	printf("|||||||STACK_A||||||\n");
	i = 0;
	while (i < a->current_len)
	{
		printf("%d\n", a->nbrs[i]);
		i++;
	}
	printf("|||||||BECOMES||||||\n");
	//ft_swap(a);
	pus(a, b);
	i = 0;
	printf("|||||||STACK_A||||||\n");
	while (i < a->current_len)
	{
		printf("%d\n", a->nbrs[i]);
		i++;
	}
	i = 0;
	printf("|||||||STACK_B||||||\n");
	while (i < b->current_len)
	{
		printf("%d\n", b->nbrs[i]);
		i++;
	}

*/

}
