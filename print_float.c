/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerard <mgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 03:05:15 by mgerard           #+#    #+#             */
/*   Updated: 2026/05/14 21:23:35 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*print_float(float nb)
{
	if (nb == 1)
		return (ft_strdup("100"));
	if (nb == 0)
		return (ft_strdup("0"));
	nb *= 10000;
	return (ft_itoa((int)nb, 4));
}
