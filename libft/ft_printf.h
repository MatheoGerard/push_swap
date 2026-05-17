/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:46:38 by nlovius           #+#    #+#             */
/*   Updated: 2026/04/29 16:27:18 by nlovius          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(va_list args);
int	ft_putstr(va_list args);
int	ft_put_u(va_list args);
int	ft_putnbr(va_list args);
int	ft_puthexa(va_list args);
int	ft_puthexa_big(va_list args);
int	ft_put_p(va_list args);
int	ft_putpercent(va_list args);
int	ft_printf(const char *str, ...);
#endif
