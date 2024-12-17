/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:09:25 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/12/17 22:28:51 by jvidal-t         ###   ########.fr       */
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

# define BRIGHT_RED "\033[91m"
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

typedef enum e_message
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
	MSG_MUT,
	MSG_EXIT
}					t_message;

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
	bool			threads_error;
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
	long			f_printend;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	struct timeval	tv;
	t_philo			philo;
}					t_data;

// utils 1
int					not_space_or_sign(char c);
long				ft_atol(const char *s);
int					ft_perror(t_message msg);
void				free_forks(t_data *ar);
void				check_msg(t_message msg, t_data *ar, t_data *data,
						long current_time_ms);
// utils 2
void				print_status(t_message msg, t_data *ar, t_data *data);
int					check_argv(int argc, char **argv);
int					check_valid_input(t_data *data);
int					parse_argv(char **argv, t_data *data);
void				init_philo(t_data *ar, t_data *data);
// utils 3
bool				check_alive(t_data *ar, t_data *data);
bool				get_forks(t_data *ar, t_data *data);
void				eat(t_data *ar, t_data *data);
void				try_to_eat(t_data *ar, t_data *data);
void				philo_think(t_data *ar, t_data *data);
// utils 4
void				philo_sleep(t_data *ar, t_data *data);
void				*work(void *arg);
void				clear_mutex(t_data *data);
int					init_struct(t_data *data);
int					create_stuff(t_data *data, pthread_t **philo);

#endif