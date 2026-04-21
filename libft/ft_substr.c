/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:50:43 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/20 15:51:33 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lensub;
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	lensub = ft_strlen(&s[start]);
	if (lensub < len)
		len = lensub;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (sub);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
#include <stdio.h>
int	main(void)
{
char	str[] = "bloop bloop find the substring bloop bloop";
unsigned int start = 0;
size_t len = 18;
char * sub;
sub = ft_substr(str, start, len);
printf("%s\n", sub);
free(sub);
 */
