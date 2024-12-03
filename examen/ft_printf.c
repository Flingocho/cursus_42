/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:08 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/20 19:01:15 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (!*s)
		return (write(1, "(null)", 6));
	while (s[counter] != '\0')
		counter += ft_putchar(s[counter]);
	return (counter);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				counter;
	char			digit;

	counter = 0;
	if (nb < 0)
	{
		counter += ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		counter += ft_putnbr(nbr / 10);
	digit = nbr % 10 + '0';
	counter += ft_putchar(digit);
	return (counter);
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int		counter;
	char	digit;

	counter = 0;
	if (nb >= 16)
		counter += ft_putnbr_base(nb / 16, base);
	digit = base[nb % 16];
	counter += ft_putchar(digit);
	return (counter);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				counter += ft_putstr(va_arg(ap, char *));
			else if (*format == 'd')
				counter += ft_putnbr(va_arg(ap, int));
			else if (*format == 'x')
				counter += ft_putnbr_base(va_arg(ap, unsigned int),
						"0123456789abcdef");
		}
		else
			counter += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (counter);
}

// int	main(void)
// {
// 	int test;

// 	test = 0;
// 	test = ft_printf("Escribo normal! %s, %d, %x\n", "boboo", INT_MIN, -1);
// 	return (0);
// }
