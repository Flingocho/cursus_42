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

// bool	get_forks(t_data *data)
// {
// 	if (data->philo.philo_id != data->n_philosophers)
// 	{
// 		if (data->philo.forks[data->philo.philo_id] == 0
// 			&& data->philo.forks[data->philo.philo_id - 1] == 0)
// 		{
// 			data->philo.forks[data->philo.philo_id] = 1;
// 			data->philo.forks[data->philo.philo_id - 1] = 1;
// 			return (true);
// 		}
// 	}
// 	else if (data->philo.philo_id == data->n_philosophers)
// 	{
// 		if (data->philo.forks[data->philo.philo_id - 1] == 0
// 			&& data->philo.forks[0] == 0)
// 		{
// 			data->philo.forks[data->philo.philo_id - 1] = 1;
// 			data->philo.forks[0] = 1;
// 			return (true);
// 		}
// 	}
// 	return (false);
// }

// bool	check_alive(t_data *data)
// {
// 	gettimeofday(&data->tv, NULL);
// 	if (data->philo.death_threshold == data->tv.tv_usec)
// 	{
// 		printf(RED "%ld philosopfer number %d DEAD!\n" RESET "",
// 			data->tv.tv_usec, data->philo.philo_id);
// 		pthread_exit(NULL);
// 		//aqui hay que cerrar todos los hilos
// 	}
// 	return (true);
// }

// void	philo_think(t_data *data)
// {
// 	if (check_alive(data))
// 	{
// 		data->philo.saciated = false;
// 	}
// }

// void	philo_sleep(t_data *data)
// {
// 	if (check_alive(data))
// 	{
// 		gettimeofday(&data->tv, NULL);
// 		printf("%ld philosopher %d sleeping Zzz..\n", data->tv.tv_usec,
// 			data->philo.philo_id);
// 		usleep(data->philo.time_to_sleep);
// 		philo_think(data);
// 	}
// }

// void	eat(t_data *data)
// {
// 	if (check_alive(data))
// 	{
// 		gettimeofday(&data->tv, NULL);
// 		printf("%ld philosopher %d eating nam nam\n", data->tv.tv_usec,
// 			data->philo.philo_id);
// 		usleep(data->philo.time_to_eat);
// 		data->philo.saciated = true;
// 		gettimeofday(&data->tv, NULL);
// 		data->philo.death_threshold = data->tv.tv_usec
// 			+ data->philo.time_to_die;
// 		if (data->philo.philo_id != data->n_philosophers)
// 		{
// 			data->philo.forks[data->philo.philo_id] = 0;
// 			data->philo.forks[data->philo.philo_id - 1] = 0;
// 		}
// 		if (data->philo.philo_id == data->n_philosophers)
// 		{
// 			data->philo.forks[data->philo.philo_id - 1] = 0;
// 			data->philo.forks[0] = 0;
// 		}
// 		if (data->philo.number_of_times_to_eat > 0)
// 			data->philo.number_of_times_to_eat -= 1;
// 		philo_sleep(data);
// 	}
// }

// void	try_to_eat(t_data *data)
// {
// 	if (check_alive(data))
// 	{
// 		pthread_mutex_lock(&data->lock);
// 		if (get_forks(data))
// 		{
// 			pthread_mutex_unlock(&data->lock);
// 			eat(data);
// 		}
// 		pthread_mutex_unlock(&data->lock);
// 	}
// }

// void	*work(void *arg)
// {
// 	t_data	data;

// 	data = *(t_data *)arg;
// 	data.philo.philo_id = data.i;
// 	gettimeofday(&data.tv, NULL);
// 	data.philo.death_threshold = data.tv.tv_usec + data.philo.time_to_die;
// 	while (data.philo.alive && data.philo.number_of_times_to_eat != 0)
// 	{
// 		printf("%ld philosopher %d is thinking..\n", data.tv.tv_usec,
// 			data.philo.philo_id);
// 		try_to_eat(&data);
// 	}
// 	gettimeofday(&data.tv, NULL);
// 	if (data.philo.alive && data.philo.number_of_times_to_eat == 0)
// 		printf("%ld philoopher %d survived! :D\n", data.tv.tv_usec,
// 			data.philo.philo_id);
// 	return (NULL);
// }

// int	init_philosophers(t_data *data, char **argv)
// {
// 	unsigned int	i;

// 	i = 0;
// 	pthread_mutex_init(&data->lock, NULL);
// 	data->n_philosophers = ft_atoi(argv[1]);
// 	data->philo.time_to_die = ft_atoi(argv[2]);
// 	data->philo.time_to_eat = ft_atoi(argv[3]);
// 	data->philo.time_to_sleep = ft_atoi(argv[4]);
// 	data->philo.number_of_times_to_eat = ft_atoi(argv[5]);
// 	data->philo.alive = true;
// 	data->philo.saciated = false;
// 	data->philo.death_threshold = data->tv.tv_usec + data->philo.time_to_die;
// 	data->philo.forks = malloc(sizeof(int) * data->n_philosophers);
// 	while (i < data->n_philosophers)
// 		data->philo.forks[i++] = 0;
// 	return (0);
// }

//_____________________________________________________________________________________________________

int	not_space_or_sign(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '+' || c == '-')
		return (ERROR);
	return (OK);
}

// already checked for digits, avoid redundancy with this atol
// put me in the same file with the parse_argv()
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

int	ft_perror(e_message msg)
{
	if (msg == MSG_EXIT)
	{
		write(2, "Exiting...\n", 12);
		return (ERROR);
	}
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
		write(2, "ex:: ./philo 5 800 200 200 7\n", 30);
		return (ERROR);
	}
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
	else if (data->time_to_sleep < 60)
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

// void	init_data(t_data *data)
// {
// }

int	main(int argc, char **argv)
{
	t_data data;

	if (OK == check_argv(argc, argv) && OK == parse_argv(argv, &data))
	{
		printf(GREEN "No errors found\n" RESET);
		// init_data(&data);
		// start_simulation(&data);
		// clean_data;
	}
	else
		return (ft_perror(MSG_EXIT));

	return (0);
}