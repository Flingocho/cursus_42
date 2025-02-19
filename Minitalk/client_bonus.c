/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:18:31 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/18 14:40:45 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
	if (sig == SIGUSR2)
		g_ack_received = 3;
}

void	send_len_by_bits(t_mini *client)
{
	int	i;

	i = -1;
	if (g_ack_received == 3)
		return ;
	while (++i < 32)
	{
		g_ack_received = 0;
		if (client->len & 0x01)
			kill(client->pid, SIGUSR2);
		else
			kill(client->pid, SIGUSR1);
		client->len = client->len >> 1;
		while (!g_ack_received)
			usleep(WAIT_TIME);
	}
}

void	send_char_by_bits(int pid, char c)
{
	int	i;

	i = -1;
	if (g_ack_received == 3)
		return ;
	while (++i < 8)
	{
		g_ack_received = 0;
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		while (!g_ack_received)
			usleep(WAIT_TIME);
	}
}

void	init(t_mini *client, int argc, char **argv)
{
	int	i;

	client->pid = 0;
	client->str_to_send = NULL;
	client->len = 0;
	if (argc != 3)
		ft_printf("Please use ./client + pid + string\n");
	else
	{
		if (check_errors(client, argv) == -1)
			return ;
		client->str_to_send = argv[2];
		client->len = ft_strlen(client->str_to_send);
		send_len_by_bits(client);
		g_ack_received = 0;
		i = -1;
		while (client->str_to_send[++i])
		{
			send_char_by_bits(client->pid, client->str_to_send[i]);
			g_ack_received = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	t_mini				client;
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Error registering SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error registering SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
	init(&client, argc, argv);
	return (0);
}
