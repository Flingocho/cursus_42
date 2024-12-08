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
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
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
	MSG_MALLOC,
	MSG_PTHREAD,
	MSG_EXIT
}					e_message;

typedef struct s_philo
{
	unsigned int	id;
	long int		death_threshold;
	long			times_ate;
	bool			alive;
	bool			saciated;
}					t_philo;

typedef struct s_data
{
	long			i;
	long			threads_created;
	long			sim_start;
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long			number_of_times_to_eat;
	long			n_philosophers;
	long			all_ate;
	int				*forks;
	pthread_mutex_t	mutex_id;
	pthread_mutex_t	mutex_wait;
	pthread_mutex_t	mutex_fork;
	struct timeval	tv;
	t_philo			philo;
}					t_data;

// actions
void				philo_think(t_data *ar, t_data *data);
void				try_to_eat(t_data *ar, t_data *data);
bool				get_forks(t_data *data);
void				eat(t_data *ar, t_data *data);
void				philo_sleep(t_data *ar, t_data *data);
void				philo_survived(t_data *ar, t_data *data);

#endif