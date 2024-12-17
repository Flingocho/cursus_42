/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:21:05 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/17 22:21:40 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_alive(t_data *ar, t_data *data)
{
	long	current_time_ms;

	gettimeofday(&ar->tv, NULL);
	current_time_ms = (ar->tv.tv_sec * 1000) + (ar->tv.tv_usec / 1000);
	if (current_time_ms >= data->philo.death_threshold)
	{
		print_status(MSG_DIE, ar, data);
		pthread_exit(NULL);
	}
	return (true);
}

bool	get_forks(t_data *ar, t_data *data)
{
	if (data->philo.id != ar->n_philosophers && ar->all_alive)
	{
		if (!pthread_mutex_lock(&ar->forks[data->philo.id]))
			print_status(MSG_FORK, ar, data);
		if (!pthread_mutex_lock(&ar->forks[data->philo.id - 1]))
			print_status(MSG_FORK, ar, data);
		return (true);
	}
	else if (data->philo.id == ar->n_philosophers)
	{
		if (!pthread_mutex_lock(&ar->forks[0]))
			print_status(MSG_FORK, ar, data);
		if (!pthread_mutex_lock(&ar->forks[data->philo.id - 1]))
			print_status(MSG_FORK, ar, data);
		return (true);
	}
	return (false);
}

void	eat(t_data *ar, t_data *data)
{
	long	current_time_ms;

	if (!(check_alive(ar, data) && ar->all_alive == true))
		pthread_exit(NULL);
	gettimeofday(&ar->tv, NULL);
	current_time_ms = (ar->tv.tv_sec * 1000) + (ar->tv.tv_usec / 1000);
	data->philo.death_threshold = current_time_ms + ar->time_to_die;
	print_status(MSG_EAT, ar, data);
	usleep(ar->time_to_eat * 1000);
	if (data->philo.id != data->n_philosophers)
	{
		pthread_mutex_unlock(&ar->forks[data->philo.id]);
		pthread_mutex_unlock(&ar->forks[data->philo.id - 1]);
	}
	else if (data->philo.id == data->n_philosophers)
	{
		pthread_mutex_unlock(&ar->forks[0]);
		pthread_mutex_unlock(&ar->forks[data->philo.id - 1]);
	}
	data->philo.times_ate++;
	if (data->philo.times_ate == data->number_of_times_to_eat)
		ar->all_ate++;
	if (ar->all_ate >= ar->n_philosophers)
		pthread_exit(NULL);
	philo_sleep(ar, data);
}

void	try_to_eat(t_data *ar, t_data *data)
{
	while (check_alive(ar, data) && ar->all_alive == true)
	{
		if (get_forks(ar, data) == true && ar->all_alive == true)
		{
			break ;
		}
		usleep(100);
	}
	if (ar->all_alive == false)
		pthread_exit(NULL);
	eat(ar, data);
}

void	philo_think(t_data *ar, t_data *data)
{
	if (check_alive(ar, data) && ar->all_alive == true)
		print_status(MSG_THINK, ar, data);
	else
		pthread_exit(NULL);
	try_to_eat(ar, data);
}
