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
# include "libft.h"
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
# define OK 0

typedef enum
{
	MSG_DIGIT,
	MSG_ARGC,
	MSG_SPCE,
	MSG_SUM,
	MSG_MS,
	MSG_MAX,
	MSG_EXIT
}					e_message;


typedef struct s_philo
{
	unsigned int	philo_id;
	long int		death_threshold;
	bool			alive;
	bool			saciated;
	int				*forks;
}					t_philo;

typedef struct s_data
{
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long			number_of_times_to_eat;
	long			n_philosophers;
	pthread_mutex_t	lock;
	struct timeval	tv;
	t_philo			philo;
}					t_data;

#endif