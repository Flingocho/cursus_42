/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:48:32 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/09 20:56:41 by jvidal-t         ###   ########.fr       */
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
		else if (msg == MSG_MALLOC)
			write(2, "malloc allocation failed\n", 26);
		else if (msg == MSG_PTHREAD)
			write(2, "thread creation failed\n", 24);
		write(2, "ex:: ./philo 5 800 200 200 7\n", 30);
		return (ERROR);
	}
}

void	print_status(e_message msg, t_data *ar, t_data *data)
{
	long	current_time_ms;

	gettimeofday(&ar->tv, NULL);
	current_time_ms = (ar->tv.tv_sec * 1000) + (ar->tv.tv_usec / 1000);
	pthread_mutex_lock(&ar->print);
	if (msg == MSG_THINK)
		printf(BRIGHT_CYAN "%04ld philosopher number %03d is thinking!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_EAT)
		printf(BRIGHT_YELLOW "%04ld philosopher number %03d is eating!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_SLEEP)
		printf(BRIGHT_MAGENTA "%04ld philosopher number %03d is sleeping!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_FORK)
		printf(BRIGHT_BLACK "%04ld philosopher number %03d has taken a fork!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_SURV)
		printf(BRIGHT_GREEN "%04ld philosopher number %03d has SURVIVED\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
	else if (msg == MSG_DIE)
	{
		printf(BRIGHT_RED "%04ld philosopher number %03d HAS DIED!\n" RESET,
			current_time_ms - data->sim_start, data->philo.id);
		return ;
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

bool	check_alive(t_data *ar, t_data *data)
{
	long	current_time_ms;

	gettimeofday(&ar->tv, NULL);
	current_time_ms = (ar->tv.tv_sec * 1000) + (ar->tv.tv_usec / 1000);
	if (current_time_ms >= data->philo.death_threshold)
	{
		print_status(MSG_DIE, ar, data);
		ar->all_alive = false;
		pthread_exit(NULL);
	}
	return (true);
}

void	philo_survived(t_data *ar, t_data *data)
{
	print_status(MSG_SURV, ar, data);
}

bool	get_forks(t_data *ar, t_data *data)
{
	if (data->philo.id != ar->n_philosophers)
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

	if (check_alive(ar, data))
	{
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
		if (data->philo.times_ate == ar->number_of_times_to_eat)
			ar->all_ate++;
		if (ar->all_ate >= ar->n_philosophers)
		{
			philo_survived(ar, data);
			pthread_exit(NULL);
		}
		philo_sleep(ar, data);
	}
}

void	try_to_eat(t_data *ar, t_data *data)
{
	while (check_alive(ar, data))
	{
		if (get_forks(ar, data) == true)
		{
			break ;
		}
	}
	eat(ar, data);
}

void	philo_think(t_data *ar, t_data *data)
{
	if (check_alive(ar, data))
	{
		print_status(MSG_THINK, ar, data);
	}
	if (check_alive(ar, data))
		try_to_eat(ar, data);
}

void	philo_sleep(t_data *ar, t_data *data)
{
	if (check_alive(ar, data))
	{
		print_status(MSG_SLEEP, ar, data);
		usleep(ar->time_to_sleep * 1000);
		philo_think(ar, data);
	}
}

void	*work(void *arg)
{
	t_data	*ar;
	t_data	data;

	ar = (t_data *)arg;
	data = *(t_data *)arg;
	ar->threads_created++;
	data.philo.id = ar->threads_created;
	while (true)
	{
		if (ar->threads_created == ar->n_philosophers)
		{
			break ;
		}
		// limpiar threads si fallo hasta threads_created
	}
	init_philo(ar, &data);
	philo_think(ar, &data);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data data;
	pthread_t *philo;

	gettimeofday(&data.tv, NULL);
	data.i = 0;
	data.threads_created = 0;
	data.philo.times_ate = 0;
	data.all_ate = 0;
	data.i = 0;
	data.all_alive = true;
	pthread_mutex_init(&data.print, NULL);
	if (OK == check_argv(argc, argv) && OK == parse_argv(argv, &data))
	{
		data.forks = malloc(sizeof(pthread_mutex_t) * data.n_philosophers);
		if (!data.forks)
			return (ft_perror(MSG_MALLOC));
		while (data.i < data.n_philosophers)
		{
			pthread_mutex_init(&data.forks[data.i], NULL);
			data.i++;
			// check fail
		}
		philo = malloc(sizeof(pthread_t) * data.n_philosophers);
		if (!philo)
			return (ft_perror(MSG_MALLOC));
		// fallo posteriores
		data.i = 0;
		while (data.i < data.n_philosophers)
		{
			if (pthread_create(&philo[data.i++], NULL, work, (void *)&data))
				return (ft_perror(MSG_PTHREAD));
			usleep(100);
		}

		// clean_data;
		data.i = 0;
		while (philo[data.i] && data.i < data.n_philosophers)
		{
			pthread_mutex_destroy(&data.forks[data.i]);
			pthread_mutex_destroy(&data.print);
			pthread_join(philo[data.i++], NULL);
		}
	}
	else
		return (ft_perror(MSG_EXIT));
	return (0);
}