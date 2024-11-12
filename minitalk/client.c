/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:18:31 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/12 16:06:05 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

void	init(t_mini *client)
{
	client->len = 0;
	client->pid = 0;
	client->str_to_send = NULL;
}

int	check_errors(t_mini *client, char **argv)
{
	int	i;

	i = -1;
	while (argv[1][++i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("PID is not digits!\n");
			return (-1);
		}
	}
	client->pid = ft_atoi(argv[1]);
	if (client->pid < 0)
		return (-1);
	i = -1;
	while (argv[2][++i])
		if (!ft_isprint(argv[2][i]))
		{
			ft_printf("char set not printable!\n");
			return (-1);
		}
	return (0);
}
void	send_len_by_bits(t_mini *client)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (client->len & 0x01)
			kill(client->pid, SIGUSR2);
		else
			kill(client->pid, SIGUSR1);
		client->len = client->len >> 1;
		usleep(WAIT_TIME);
	}
}

void	send_char_by_bits(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}
}

int	main(int argc, char **argv)
{
	t_mini client;
	int i;

	i = -1;
	init(&client);
	if (argc != 3)
		ft_printf("Please use ./client + pid + string\n");
	else
	{
		if (check_errors(&client, argv) == -1)
			return (-1);
		client.str_to_send = argv[2];
		client.len = ft_strlen(client.str_to_send);
	}
	send_len_by_bits(&client);
	while (client.str_to_send[++i])
		send_char_by_bits(client.str_to_send[i], client.pid);
	send_char_by_bits(client.str_to_send[i], client.pid);
	return (0);
}