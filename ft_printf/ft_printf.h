/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:29:01 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/03 20:17:47 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putformat(char *s);
int	ft_putstr(char *s);
int	ft_printf(char const *format, ...);
int	format_selector(char const *format, va_list arg);
int	ft_putnbr_u(unsigned int nbr);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putptr(unsigned long long nbr, char *base, int first);

#endif