/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:09:25 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/09 20:19:48 by jvidal-t         ###   ########.fr       */
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

#define BRIGHT_RED "\033[91m"
# define BRIGHT_GREEN "\033[92m"
# define BRIGHT_BLACK "\033[90m"
# define BRIGHT_CYAN "\033[96m"
# define BRIGHT_MAGENTA "\033[95m"
# define BRIGHT_YELLOW "\033[93m"
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
	MSG_THINK,
	MSG_EAT,
	MSG_SLEEP,
	MSG_FORK,
	MSG_SURV,
	MSG_DIE,

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
	bool			all_alive;
	long			i;
	long			threads_created;
	long			sim_start;
	long			time_to_die;
	long			time_to_sleep;
	long			time_to_eat;
	long			number_of_times_to_eat;
	long			n_philosophers;
	long			all_ate;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	struct timeval	tv;
	t_philo			philo;
}					t_data;

// actions
void				philo_think(t_data *ar, t_data *data);
void				try_to_eat(t_data *ar, t_data *data);
bool				get_forks(t_data *ar, t_data *data);
void				eat(t_data *ar, t_data *data);
void				philo_sleep(t_data *ar, t_data *data);
void				philo_survived(t_data *ar, t_data *data);

#endif