/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:09:25 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/03 13:12:12 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

# define ERROR 1

typedef struct s_philo
{
	unsigned int	time_to_die;
	unsigned int	time_to_sleep;
	unsigned int	time_to_eat;
	unsigned int	number_of_times_to_eat;
	unsigned int	philo_id;
	long int		death_threshold;
	bool			alive;
	bool			saciated;
	int				*forks;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t lock;
	unsigned int	i;
	unsigned int	n_philosophers;
	struct timeval	tv;
	t_philo			philo;
}					t_data;

// check_errors.c
int					check_argv(int argc, char **argv);
int					check_digits(char *str);
// utils.c
int					ft_atoi(char *str);
int					ft_isdigit(char c);

#endif