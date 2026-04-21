/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:51:14 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 12:14:07 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*numb;
	int				val_n;
	int				size;
	unsigned int	abs_val_n;

	val_n = n;
	size = (n < 0);
	while (!(val_n > -10 && val_n < 10))
	{
		val_n /= 10;
		size++;
	}
	numb = (char *)malloc((size + 2) * sizeof(char));
	if (numb == NULL)
		return (numb);
	numb[size + 1] = '\0';
	abs_val_n = (unsigned int)(n * (2 * (n > 0) - 1));
	while (size >= 0)
	{
		numb[size--] = (abs_val_n % 10) + '0';
		abs_val_n /= 10;
	}
	if (n < 0)
		numb[0] = '-';
	return (numb);
}

/*#include <stdio.h>

int     main(void)
{
        printf("%s\n", ft_itoa(-INT_MIN));
        printf("%s\n", ft_itoa(INT_MAX));
        printf("%s\n", ft_itoa(1));
        printf("%s\n", ft_itoa(-10));
        printf("%s\n", ft_itoa(-11));
        printf("%s\n", ft_itoa(-2));
        printf("%s\n", ft_itoa(4));
}*/
