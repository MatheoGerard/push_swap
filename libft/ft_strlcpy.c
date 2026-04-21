/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:40:47 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/17 17:59:05 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

/*#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	*src = "abc";
	char	dst[] = "000000";
	char	dst2[] = "000000";
	size_t	size_returned;
	size_t	size_returned2;

	size_returned = strlcpy(dst, src, 4);
	printf("%s ===> %s, returns %zu\n", src, dst, size_returned);
	size_returned2 = ft_strlcpy(dst2, src2, 4);
	printf("%s ===> %s, returns %zu\n", src2, dst2, size_returned2);
}*/
