/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:25:23 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 12:23:03 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;

	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == chr)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned char	*ptr;
	int	tab[] = {-49, 49, 1, -1, 0, -2, 2};

	ptr = (unsigned char *)ft_memchr(tab, -1, 20);
	printf("%s\n", ptr);
	ptr = (unsigned char *)memchr(tab, -1, 20);
	printf("%s\n", ptr);
}*/
