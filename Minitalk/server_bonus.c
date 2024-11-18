/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:19:03 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/18 14:37:09 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

volatile sig_atomic_t	g_len_received = 0;

void	handle_len(char **str, int sig, siginfo_t *info, int *len_val)
{
	static int	curr_bit;

	if (sig == SIGUSR2)
		*len_val |= (1 << curr_bit);
	curr_bit++;
	if (curr_bit == MAX_BITS)
	{
		*str = ft_calloc(*len_val + 1, sizeof(char));
		if (!*str)
		{
			g_len_received = 0;
			return ;
		}
		curr_bit = 0;
		kill(info->si_pid, SIGUSR2);
		g_len_received = 1;
		return ;
	}
	kill(info->si_pid, SIGUSR1);
}

void	handle_char(int sig, siginfo_t *info, char *str, int *len_val)
{
	static int	curr_bit;
	static int	char_value;
	static int	char_index;

	if (sig == SIGUSR2)
		char_value |= (1 << curr_bit);
	curr_bit++;
	if (curr_bit == BYTE_BITS)
	{
		str[char_index++] = (char)char_value;
		char_value = 0;
		curr_bit = 0;
		if (char_index == *len_val)
		{
			ft_printf("%s\n", str);
			g_len_received = 0;
			if (str)
				free(str);
			*len_val = 0;
			str = NULL;
			char_index = 0;
			kill(info->si_pid, SIGUSR2);
		}
	}
	kill(info->si_pid, SIGUSR1);
}

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	len = 0;
	static char	*str = NULL;

	(void)context;
	if (!g_len_received)
		handle_len(&str, sig, info, &len);
	else
		handle_char(sig, info, str, &len);
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
