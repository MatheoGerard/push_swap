/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 10:23:23 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 15:56:40 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt1;
	unsigned char	*pt2;

	i = 0;
	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	while (i < n)
	{
		if (pt1[i] != pt2[i])
			return (pt1[i] - pt2[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "abcdefghij";
	char	str2[] = "abcdefgxyz";

	printf("%d\n", ft_memcmp(str, str2, 7));
	printf("%d\n", memcmp(str, str2, 7));
	printf("%d\n", ft_memcmp(str2, str2, 100));
	printf("%d\n", memcmp(str2, str2, 100));
	printf("%d\n", ft_memcmp(NULL, str2, 0));
	printf("%d\n", memcmp(NULL, str2, 0));
}*/
