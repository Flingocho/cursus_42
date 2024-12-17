/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:19:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/17 22:20:40 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_message msg, t_data *ar, t_data *data)
{
	long	current_time_ms;

	pthread_mutex_lock(&ar->print);
	if (ar->all_alive == true)
	{
		gettimeofday(&ar->tv, NULL);
		current_time_ms = (ar->tv.tv_sec * 1000) + (ar->tv.tv_usec / 1000);
		if (ar->all_alive == true)
			check_msg(msg, ar, data, current_time_ms);
	}
	pthread_mutex_unlock(&ar->print);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 6 || argc == 5)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (not_space_or_sign(argv[i][j]))
					return (ft_perror(MSG_SPCE));
				else if (!ft_isdigit(argv[i][j]))
					return (ft_perror(MSG_DIGIT));
				j++;
			}
			i++;
		}
		return (OK);
	}
	return (ft_perror(MSG_ARGC));
}

int	check_valid_input(t_data *data)
{
	if ((long)data->n_philosophers > INT_MAX
		|| (long)data->time_to_die > INT_MAX
		|| (long)data->time_to_eat > INT_MAX
		|| (long)data->time_to_sleep > INT_MAX)
		return (ft_perror(MSG_MAX));
	else if (data->time_to_die <= data->time_to_eat + data->time_to_sleep)
		return (ft_perror(MSG_SUM));
	else if (data->time_to_sleep < 60 || data->time_to_die < 60
		|| data->time_to_eat < 60)
		return (ft_perror(MSG_MS));
	return (OK);
}

int	parse_argv(char **argv, t_data *data)
{
	data->n_philosophers = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->number_of_times_to_eat = ft_atol(argv[5]);
	else
		data->number_of_times_to_eat = -1;
	if (OK == check_valid_input(data))
		return (OK);
	else
		return (ERROR);
}

void	init_philo(t_data *ar, t_data *data)
{
	gettimeofday(&ar->tv, NULL);
	data->sim_start = (ar->tv.tv_sec * 1000) + (ar->tv.tv_usec / 1000);
	data->philo.death_threshold = data->sim_start + ar->time_to_die;
}
