/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:38:00 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/21 13:29:43 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	move_set_1(t_vars *vars)
{
    static int direction;
    
    if (vars->enemy_pos_row == 1)
        direction = 0;
    if (vars->enemy_pos_row == vars->map_rows - 2)
        direction = 1;
    if (direction == 0)
        vars->enemy_pos_row += 1;
    if (direction == 1)
        vars->enemy_pos_row -= 1;
}

void	move_set_2(t_vars *vars)
{
    static int direction;
    
    if (vars->enemy_pos_row == 1)
        direction = 0;
    if (vars->enemy_pos_row == vars->map_rows - 2)
        direction = 1;
    if (direction == 0)
        vars->enemy_pos_row += 1;
    if (direction == 1)
        vars->enemy_pos_row -= 1;
}

void	move_set_3(t_vars *vars)
{
    static int direction;
    
    if (vars->enemy_pos_row == 1)
        direction = 0;
    if (vars->enemy_pos_row == vars->map_rows - 2)
        direction = 1;
    if (direction == 0)
        vars->enemy_pos_row += 1;
    if (direction == 1)
        vars->enemy_pos_row -= 1;
}

void	check_map_enemy(t_vars *vars)
{
	// PUT YPUR FUCKING STRCMP
	if (strcmp(vars->map_path, "map.ber") == 0)
		move_set_1(vars);
    if (strcmp(vars->map_path, "map2.ber") == 0)
		move_set_2(vars);
    if (strcmp(vars->map_path, "map3.ber") == 0)
		move_set_3(vars);
}