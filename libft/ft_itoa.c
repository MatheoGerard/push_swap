/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:51:14 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/13 05:20:01 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n, int size)
{
	char			*numb;
	int				val_n;

	val_n = n;
	numb = (char *)malloc(size + 1 + (n > 999) * sizeof(char));
	if (numb == NULL)
		return (numb);
	size -= (n < 1000);
	numb[size] = '\0';
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
/*
#include <stdio.h>

int     main(void)
{
        printf("%s\n", ft_itoa(450, 4));
}
*/
