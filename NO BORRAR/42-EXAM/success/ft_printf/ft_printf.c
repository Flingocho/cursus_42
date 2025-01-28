/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:13:28 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/27 15:13:29 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return(write(1, "(null)", 6));
	else
		while (str[counter] != '\0')
			counter += ft_putchar(str[counter]);
	return (counter);
}

int	ft_putnbr(int nbr)
{
	int				counter;
	unsigned int	unb;
	char			digit;

	counter = 0;
	if (nbr < 0)
	{
		counter += ft_putchar('-');
		unb = nbr * -1;
	}
	else
		unb = nbr;
	if (unb >= 10)
		counter += ft_putnbr(unb / 10);
	digit = (unb % 10) + 48;
	counter += ft_putchar(digit);
	return (counter);
}

int	ft_puthex(unsigned int nb, char *base)
{
	int		counter;
	char	digit;

	counter = 0;
	if (nb >= 16)
		counter += ft_puthex(nb / 16, base);
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
				counter += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
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
// 	int countermio;
// 	int counterprintf;
// 	countermio = ft_printf("hola!, %d, %d,  %s, %x\n", INT_MIN, INT_MAX, "TEXTOOOOO", INT_MAX);
// 	counterprintf = printf("hola!, %d, %d, %s, %x\n", INT_MIN, INT_MAX, "TEXTOOOOO", INT_MAX);
// 	printf("counter mio: %d\n", countermio);
//     printf("counter printf: %d\n", counterprintf);
// 	return (0);
// }