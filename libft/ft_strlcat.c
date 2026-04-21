/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:14:50 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/17 17:09:16 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	lendst = 0;
	lensrc = ft_strlen(src);
	i = 0;
	while (lendst < size && dst[lendst])
		lendst++;
	if (lendst == size)
		return (size + lensrc);
	while (src[i] && (lendst + i + 1) < size)
	{
		dst[i + lendst] = src[i];
		i++;
	}
	dst[i + lendst] = '\0';
	return (lendst + lensrc);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dst[100] = "Hello ";
	char	dst2[100] = "Hello ";
	char	src[] = "itoa ily";
	size_t	size = 11;

	printf("%zu\n", strlcat(dst, src, size));
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcat(dst2, src, size));
	printf("%s\n", dst2);
	
}*/
