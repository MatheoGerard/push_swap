/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:28:52 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/16 13:09:33 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lentot;
	size_t	i;
	size_t	j;
	char	*joined;

	i = 0;
	j = 0;
	lentot = 0;
	if (s1 && s2)
		lentot = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc((lentot + 1) * sizeof(char));
	if (joined == NULL)
		return (joined);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
/*
#include <stdio.h>

int	main(void)
{
    char *s1 = NULL;
    char *s2 = "world!";
    char *res;

    res = ft_strjoin(s1, s2);
    if (res != NULL)
    {
        printf("S1: %s\n", s1);
        printf("S2: %s\n", s2);
        printf("Joined: %s\n", res);
        free(res);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return (0);
}
*/
