/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:17:33 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/17 22:18:25 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	not_space_or_sign(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '+' || c == '-')
		return (ERROR);
	return (OK);
}

long	ft_atol(const char *s)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
		|| *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		ret = ret * 10 + (*s++ - '0');
	return (ret * sign);
}

int	ft_perror(t_message msg)
{
	if (msg == MSG_EXIT)
		write(2, "Exiting...\n", 12);
	else
	{
		write(2, RED "ERROR:: " RESET, 17);
		if (msg == MSG_DIGIT)
			write(2, "only non zero positive numbers accepted\n", 41);
		else if (msg == MSG_ARGC)
			write(2, "invalid arg number\n", 20);
		else if (msg == MSG_SPCE)
			write(2, "avoid using spaces or signs\n", 29);
		else if (msg == MSG_SUM)
			write(2, "time_to_die is lower than needed\n", 34);
		else if (msg == MSG_MAX)
			write(2, "do not exceed INT_MAX values\n", 30);
		else if (msg == MSG_MS)
			write(2, "do not use lower than 60 ms\n", 29);
		else if (msg == MSG_MALLOC)
			write(2, "malloc allocation failed\n", 26);
		else if (msg == MSG_PTHREAD)
			write(2, "thread creation failed\n", 24);
		else if (msg == MSG_MUT)
			write(2, "mutex init failed\n", 19);
	}
	return (ERROR);
}

void	free_forks(t_data *ar)
{
	int	i;

	i = 0;
	while (i < ar->n_philosophers)
	{
		pthread_mutex_unlock(&ar->forks[i]);
		i++;
	}
}

void	check_msg(t_message msg, t_data *ar, t_data *data, long current_time_ms)
{
	if (msg == MSG_THINK)
		printf(BRIGHT_CYAN "%04ld philosopher number%03d is thinking !\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_EAT)
		printf(BRIGHT_YELLOW "%04ld philosopher number%03d is eating!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_SLEEP)
		printf(BRIGHT_MAGENTA "%04ld philosopher number%03d is sleeping!\n"
			RESET, current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_FORK)
		printf(BRIGHT_BLACK "%04ld philosopher number%03d has taken a fork!\n"
			RESET, current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_SURV)
		printf(BRIGHT_GREEN "%04ld PHILOSOPHERS HAVE SURVIVED! :D\n" RESET,
			current_time_ms - data->sim_start);
	else if (msg == MSG_DIE)
	{
		ar->all_alive = false;
		printf(BRIGHT_RED "%04ld philosopher number%03d HAS DIED!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
		free_forks(ar);
	}
}
