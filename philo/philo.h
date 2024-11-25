/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:09:25 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/25 20:32:51 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

# define ERROR 1

typedef struct s_philo
{
	int				time_to_die;
	int				tim_to_sleep;
	int				number_of_times_to_eat;
}					t_philo;

typedef struct s_data
{
	size_t			i;
	int				n_philosophers;
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