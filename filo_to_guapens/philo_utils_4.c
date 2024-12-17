/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:22:02 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/17 22:22:45 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_data *ar, t_data *data)
{
	if (check_alive(ar, data) && ar->all_alive == true)
	{
		print_status(MSG_SLEEP, ar, data);
		usleep(ar->time_to_sleep * 1000);
		philo_think(ar, data);
	}
	else
		pthread_exit(NULL);
}

void	*work(void *arg)
{
	t_data	*ar;
	t_data	data;

	ar = (t_data *)arg;
	data = *(t_data *)arg;
	ar->threads_created++;
	data.philo.id = ar->threads_created;
	while (ar->threads_error == false)
	{
		if (ar->threads_created == ar->n_philosophers)
		{
			break ;
		}
		usleep(100);
	}
	if (ar->threads_error == true)
		pthread_exit(NULL);
	init_philo(ar, &data);
	if (data.philo.id % 2 == 0)
		usleep(100);
	philo_think(ar, &data);
	return (NULL);
}

void	clear_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->i)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

int	init_struct(t_data *data)
{
	gettimeofday(&data->tv, NULL);
	data->threads_error = false;
	data->i = 0;
	data->threads_created = 0;
	data->philo.times_ate = 0;
	data->all_ate = 0;
	data->i = 0;
	data->f_printend = 0;
	data->all_alive = true;
	if (pthread_mutex_init(&data->print, NULL))
		return (ft_perror(MSG_MUT));
	return (OK);
}

int	create_stuff(t_data *data, pthread_t **philo)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philosophers);
	if (!data->forks)
		return (ft_perror(MSG_MALLOC));
	while (data->i < data->n_philosophers)
	{
		if (pthread_mutex_init(&data->forks[data->i], NULL))
		{
			free(data->forks);
			clear_mutex(data);
			return (ft_perror(MSG_MUT));
		}
		data->i++;
	}
	*philo = malloc(sizeof(pthread_t) * data->n_philosophers);
	if (!*philo)
	{
		clear_mutex(data);
		free(data->forks);
		return (ft_perror(MSG_MALLOC));
	}
	data->i = 0;
	return (OK);
}
