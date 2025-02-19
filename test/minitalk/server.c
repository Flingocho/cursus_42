/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:19:03 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/15 12:46:23 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

int	recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 && power == 0)
		return (1);
	else
		return (nb * recursive_power(nb, power - 1));
}

void	restart_vars(int *len_received, char **str, int *i, int *char_val,
		int *curr_bit)
{
	*char_val = 0;
	*curr_bit = 0;
	*i = 0;
	*len_received = 0;
	if (str)
	{
		write(1, *str, ft_strlen(*str));
		write(1, "\n", 2);
		free(*str);
		*str = NULL;
	}
}

void	get_len(int *curr_bit, char **str, int *received, int s)
{
	static int	len_val;

	if (s == SIGUSR2)
		len_val += recursive_power(2, *curr_bit);
	if (*curr_bit == MAX_BITS)
	{
		*received = 1;
		if (*str)
			free(*str);
		*str = ft_calloc(len_val + 1, sizeof(char));
		if (*str == NULL)
		{
			*received = 0;
			return ;
		}
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

void	get_info(int signal)
{
	static int	char_value = 0;
	static int	current_bit = 0;
	static int	len = 0;
	static int	i = 0;
	static char	*str = NULL;

	if (!len)
	{
		get_len(&current_bit, &str, &len, signal);
	}
	else
	{
		if (signal == SIGUSR2)
			char_value += recursive_power(2, current_bit);
		if (current_bit == 7)
		{
			str[i++] = char_value;
			current_bit = 0;
			if (char_value == 0)
			{
				restart_vars(&len, &str, &i, &char_value, &current_bit);
				return ;
			}
			char_value = 0;
		}
		else
		{
			current_bit++;
		}
		kill(pid, SIGUSR1);
	}
}
int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR2, get_info);
	signal(SIGUSR1, get_info);
	while (1)
		usleep(WAIT_TIME);
	return (0);
}