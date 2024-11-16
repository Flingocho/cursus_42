/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:19:03 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/16 20:59:40 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

volatile sig_atomic_t	len_received = 0;

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	curr_bit = 0;
	static int	bit = 0;
	static int	len_val = 0;
	static char	*str = NULL;
	static int	received = 0;
	static int	char_value = 0;
	static int	char_index = 0;

	if (len_received == 0)
	{
		if (sig == SIGUSR1 || sig == SIGUSR2)
		{
			if (!received)
			{
				if (sig == SIGUSR2)
					len_val |= (1 << curr_bit);
				curr_bit++;
				if (curr_bit == 32)
				{
					received = 1;
					str = ft_calloc(len_val + 1, sizeof(char));
					if (!str)
					{
						received = 0;
						ft_printf("Memory allocation failed!\n");
						return ;
					}
					curr_bit = 0;
					kill(info->si_pid, SIGUSR2);
					len_received = 1;
					return ;
				}
				kill(info->si_pid, SIGUSR1);
			}
		}
	}
	else
	{
		if (sig == SIGUSR2)
			char_value |= (1 << bit);
		bit++;
		if (bit == 8)
		{
			str[char_index] = (char)char_value;
			char_index++;
			char_value = 0;
			bit = 0;
			if (char_index == len_val)
			{
				ft_printf("%s\n", str);
				len_received = 0;
				if (str)
					free(str);
				curr_bit = 0;
				bit = 0;
				len_val = 0;
				str = NULL;
				received = 0;
				char_value = 0;
				char_index = 0;
				kill(info->si_pid, SIGUSR2);
			}
		}
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("SERVER PID: %d\n", getpid());
	sa.sa_sigaction = sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
