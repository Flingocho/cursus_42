/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:52:12 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/11/17 17:32:05 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_BITS 32
# define BYTE_BITS  8
# define WAIT_TIME 100

typedef struct s_mini
{
	int		pid;
	int		len;
	char	*str_to_send;
}			t_mini;

int			check_errors(t_mini *client, char **argv);

#endif
