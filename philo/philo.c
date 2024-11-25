#include "philo.h"

void	*work(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	printf(GREEN "I'm philosopfer number %ld!\n", data->i);
	printf("I need to eat %d times!"RESET"\n", data->philo.number_of_times_to_eat);
	return (NULL);
}

int	init_philosophers(t_data *data, char **argv)
{
	data->n_philosophers = ft_atoi(argv[1]);
	data->philo.time_to_die = ft_atoi(argv[2]);
	data->philo.tim_to_sleep = ft_atoi(argv[3]);
	data->philo.number_of_times_to_eat = ft_atoi(argv[4]);
	return (0);
}
int	main(int argc, char **argv)
{
	t_data data;

	data.i = 0;
	if (check_argv(argc, *&argv))
		return (ERROR);
	gettimeofday(&data.tv, NULL);
	init_philosophers(&data, *&argv);

	//[NIY]need to check non negative arguments!
	pthread_t philo[data.n_philosophers];

	// Main routine
	printf("Welcome to philosophers!\n");
	printf("time: %ld\n", data.tv.tv_sec);

	// create n_philosophers threads
	while (data.i < data.n_philosophers)
	{
		if (pthread_create(&philo[data.i++], NULL, work, (void *)&data))
			return (ERROR);
		usleep(100);
	}

	// wait for all threads to end
	data.i = 0;
	while (data.i < data.n_philosophers)
		if (pthread_join(philo[data.i++], NULL))
			return (ERROR);

	return (0);
}
