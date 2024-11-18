/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:05:56 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/17 17:29:58 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

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
	return (0);
}
