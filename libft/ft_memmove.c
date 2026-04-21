/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:13:28 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 15:21:09 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	ssize_t	sign;
	char	*d;
	char	*s;
	size_t	n_underflow;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	sign = 1;
	n_underflow = n + (dest > src);
	d = (char *)dest;
	s = (char *)src;
	if (dest > src)
	{
		i = n - 1;
		sign = -1;
	}
	while (i < n_underflow)
	{
		d[i] = s[i];
		i += sign;
	}
	return (d);
}

/*#include <stdio.h>
#include <string.h>

int     main(void)
{
        char    src[] = "abcdefg";
        char    src2[] = "abcdefg";

        printf("%s ====>", src);
        memmove(&src[2], src, 3);
        printf(" %s\n", src);
        printf("%s ====>", src2);
        ft_memmove(&src2[2], src2, 3);
        printf(" %s\n", src2);
        printf("%s ====>", src);
        memmove(src, &src[2], 3);
        printf(" %s\n", src);
        printf("%s ====>", src2);
        ft_memmove(src2, &src2[2], 3);
        printf(" %s\n", src2);
}*/
