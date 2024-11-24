#include "philo.h"

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (ERROR);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
	{
		printf(RED "Please use ./philo [number_of_philosophers] [time_to_die] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
		printf("**Note that all of the arguments must be given in miliseconds**\n" RESET);
		return (ERROR);
	}
	else
		while (++i < argc)
			if (check_digits(argv[i]))
			{
				printf("Please use only numbers for each [time_argument]\n");
				return (ERROR);
			}
	return (0);
}