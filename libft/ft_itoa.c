/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:51:14 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/14 20:52:50 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n, int size)
{
	char			*numb;
	int				val_n;

	val_n = n;
	size += (n > 999);
	numb = (char *)malloc(size + 1 * sizeof(char));
	if (numb == NULL)
		return (numb);
	numb[size--] = '\0';
	while (size >= 0)
	{
		if (size == 2 - (n < 1000))
		{
			numb[size] = '.';
			size--;
			continue ;
		}
		numb[size--] = (val_n % 10) + '0';
		val_n /= 10;
	}
	return (numb);
}

/*#include <stdio.h>

int     main(void)
{
	char	*test;
	test = ft_itoa(4450, 4);
        printf("%s\n", test);
	free(test);
}*/
