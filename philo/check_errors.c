/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:09:32 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/01 17:26:04 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			i++;
		else
			return (ERROR);
	}
	if (str[i] == '\0')
		return (0);
	else
		return (ERROR);
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 6)
	{
		printf(RED "Please use ./philo [number_of_philosophers]");
		printf("[time_to_die] [time_to_eat] [time_to_sleep]");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		printf("**Note that all of the arguments");
		printf("must be given in miliseconds**\n" RESET);
		return (ERROR);
	}
	else
	{
		while (++i < argc)
		{
			if (check_digits(argv[i]))
			{
				printf("Please use only numbers for each [time_argument]\n");
				return (ERROR);
			}
		}
	}
	return (0);
}
