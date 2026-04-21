/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 11:38:24 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 14:39:35 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	while (s[i] && s[i] != chr)
		i++;
	if (s[i] == chr)
		return ((char *)&s[i]);
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "abcdef";

	printf("%s\n", ft_strchr(str, 'c'));
}*/
