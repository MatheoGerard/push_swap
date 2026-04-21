/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:25:16 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 15:23:39 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (d);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "abxyzef";
	char	dest[] = "oooooooooooooooo";
	char	src2[] = "abxyzef";
	char	dest2[] = "ooooooooooooo";

	printf("%s ====>", src);
	memcpy(&src[2], src2, 5);
	printf(" %s\n", &src[2]);
	printf("%s ====>", src2);
	ft_memcpy(&src2[2], src2, 5);
	printf(" %s\n", &src2[2]);
}*/
