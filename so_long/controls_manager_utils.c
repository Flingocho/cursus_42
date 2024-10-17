/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_manager_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:10:57 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/17 01:25:17 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_floor(t_vars *vars)
{
	if (vars->map[vars->player_pos_row][vars->player_pos_column] == '@')
	{
		vars->map[vars->player_pos_row][vars->player_pos_column] = ' ';
		vars->n_collectables += 1;
	}
	if (vars->collectables == vars->n_collectables
		&& vars->map[vars->player_pos_row][vars->player_pos_column] == 'X')
	{
		vars->map[vars->player_pos_row][vars->player_pos_column] = 'x';
        return(1);
	}
    return (0);
}