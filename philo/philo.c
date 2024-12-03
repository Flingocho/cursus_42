/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:48:32 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/03 18:21:36 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_forks(t_data *data)
{
	if (data->philo.philo_id != data->n_philosophers)
	{
		if (data->philo.forks[data->philo.philo_id] == 0
			&& data->philo.forks[data->philo.philo_id - 1] == 0)
		{
			data->philo.forks[data->philo.philo_id] = 1;
			data->philo.forks[data->philo.philo_id - 1] = 1;
			return (true);
		}
	}
	else if (data->philo.philo_id == data->n_philosophers)
	{
		if (data->philo.forks[data->philo.philo_id - 1] == 0
			&& data->philo.forks[0] == 0)
		{
			data->philo.forks[data->philo.philo_id - 1] = 1;
			data->philo.forks[0] = 1;
			return (true);
		}
	}
	return (false);
}

bool	check_alive(t_data *data)
{
	gettimeofday(&data->tv, NULL);
	if (data->philo.death_threshold == data->tv.tv_usec)
	{
		printf(RED "%ld philosopfer number %d DEAD!\n" RESET "",
			data->tv.tv_usec, data->philo.philo_id);
		pthread_exit(NULL);
		//aqui hay que cerrar todos los hilos
	}
	return (true);
}

void	philo_think(t_data *data)
{
	if (check_alive(data))
	{
		data->philo.saciated = false;
	}
}

void	philo_sleep(t_data *data)
{
	if (check_alive(data))
	{
		gettimeofday(&data->tv, NULL);
		printf("%ld philosopher %d sleeping Zzz..\n", data->tv.tv_usec,
			data->philo.philo_id);
		usleep(data->philo.time_to_sleep);
		philo_think(data);
	}
}

void	eat(t_data *data)
{
	if (check_alive(data))
	{
		gettimeofday(&data->tv, NULL);
		printf("%ld philosopher %d eating nam nam\n", data->tv.tv_usec,
			data->philo.philo_id);
		usleep(data->philo.time_to_eat);
		data->philo.saciated = true;
		gettimeofday(&data->tv, NULL);
		data->philo.death_threshold = data->tv.tv_usec
			+ data->philo.time_to_die;
		if (data->philo.philo_id != data->n_philosophers)
		{
			data->philo.forks[data->philo.philo_id] = 0;
			data->philo.forks[data->philo.philo_id - 1] = 0;
		}
		if (data->philo.philo_id == data->n_philosophers)
		{
			data->philo.forks[data->philo.philo_id - 1] = 0;
			data->philo.forks[0] = 0;
		}
		if (data->philo.number_of_times_to_eat > 0)
			data->philo.number_of_times_to_eat -= 1;
		philo_sleep(data);
	}
}

void	try_to_eat(t_data *data)
{
	if (check_alive(data))
	{
		pthread_mutex_lock(&data->lock);
		if (get_forks(data))
		{
			pthread_mutex_unlock(&data->lock);
			eat(data);
		}
		pthread_mutex_unlock(&data->lock);
	}
}

void	*work(void *arg)
{
	t_data	data;
	
	data = *(t_data *)arg;
	data.philo.philo_id = data.i;
	gettimeofday(&data.tv, NULL);
	data.philo.death_threshold = data.tv.tv_usec + data.philo.time_to_die;
	while (data.philo.alive && data.philo.number_of_times_to_eat != 0)
	{
		printf("%ld philosopher %d is thinking..\n", data.tv.tv_usec,
			data.philo.philo_id);
		try_to_eat(&data);
	}
	gettimeofday(&data.tv, NULL);
	if (data.philo.alive && data.philo.number_of_times_to_eat == 0)
		printf("%ld philoopher %d survived! :D\n", data.tv.tv_usec,
			data.philo.philo_id);
	return (NULL);
}

int	init_philosophers(t_data *data, char **argv)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_init(&data->lock, NULL);
	data->n_philosophers = ft_atoi(argv[1]);
	data->philo.time_to_die = ft_atoi(argv[2]);
	data->philo.time_to_eat = ft_atoi(argv[3]);
	data->philo.time_to_sleep = ft_atoi(argv[4]);
	data->philo.number_of_times_to_eat = ft_atoi(argv[5]);
	data->philo.alive = true;
	data->philo.saciated = false;
	data->philo.death_threshold = data->tv.tv_usec + data->philo.time_to_die;
	data->philo.forks = malloc(sizeof(int) * data->n_philosophers);
	while (i < data->n_philosophers)
		data->philo.forks[i++] = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	*philo;

	data.i = 0;
	if (check_argv(argc, *&argv))
		return (ERROR);
	gettimeofday(&data.tv, NULL);
	init_philosophers(&data, *&argv);
	philo = malloc(sizeof(pthread_t) * data.n_philosophers);
	if (!philo)
		return (ERROR);
	//[NIY]need to check non negative arguments!
	while (data.i < data.n_philosophers)
	{
		if (pthread_create(&philo[data.i++], NULL, work, (void *)&data))
			return (ERROR);
		usleep(100);
	}
	data.i = 0;
	while (data.i < data.n_philosophers)
		if (pthread_join(philo[data.i++], NULL))
			return (ERROR);
	free(data.philo.forks);
	free(philo);
	return (0);
}
