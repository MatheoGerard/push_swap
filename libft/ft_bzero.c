/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:44:39 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/14 12:23:40 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "\0abcdef";
	char	str2[] = "\0abcdef";
	int	i;

	i = 0;
	bzero(str, 21);
	ft_bzero(str2, 21);
	while (i < 1)
	{
		printf("%c\n", str[i]);
		printf("%c\n", str2[i]);
		i++;
	}
}*/
