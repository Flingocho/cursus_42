/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:48:32 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/17 22:23:06 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data, pthread_t **ph)
{
	pthread_t	*philo;

	philo = *ph;
	while (data->i < data->n_philosophers)
	{
		printf("Dentro papasito!\n");
		if (pthread_create(&philo[data->i++], NULL, work, (void *)data))
		{
			data->threads_error = true;
			free(*ph);
			free(data->forks);
			clear_mutex(data);
			while (--data->i >= 0)
				pthread_join(philo[data->i], NULL);
			return (ft_perror(MSG_PTHREAD));
		}
		usleep(100);
	}
	data->i = 0;
	return (OK);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	*philo;

	if (init_struct(&data) == OK && check_argv(argc, argv) == OK
		&& parse_argv(argv, &data) == OK)
	{
		if (create_stuff(&data, &philo) == ERROR || create_threads(&data,
				&philo))
			return (ERROR);
		while (data.i < data.n_philosophers && philo[data.i])
		{
			pthread_join(philo[data.i], NULL);
			pthread_mutex_destroy(&data.forks[data.i++]);
		}
		pthread_mutex_destroy(&data.print);
		free(data.forks);
		free(philo);
		if (data.all_alive == true)
			return (printf(BRIGHT_GREEN "PHILOSOPHERS HAVE SURVIVED!\n" RESET));
	}
	else
		return (ft_perror(MSG_EXIT));
	return (0);
}
