/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlovius <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:46:38 by nlovius           #+#    #+#             */
/*   Updated: 2026/05/17 16:43:37 by mgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int fd, va_list args);
int	ft_putstr(int fd, va_list args);
int	ft_put_u(int fd, va_list args);
int	ft_putnbr(int fd, va_list args);
int	ft_puthexa(int fd, va_list args);
int	ft_puthexa_big(int fd, va_list args);
int	ft_put_p(int fd, va_list args);
int	ft_putpercent(int fd, va_list args);
int	ft_printf(int fd, const char *str, ...);
int	print_float(int fd, va_list args);

#endif
