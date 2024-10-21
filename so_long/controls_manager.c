/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:43 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/21 13:22:49 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	key_esc(int keycode, t_vars *vars)
{
	printf("(ESC) ¡Bye! :D\n");
	free_resources(vars);
	exit(1);
}

int	key_w(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->can_move && vars->map[vars->player_pos_row
		- 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row -= 1;
		check_map_enemy(vars);
		check_floor(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	render_window(vars);
	return (0);
}

int	key_s(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->can_move && vars->map[vars->player_pos_row
		+ 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row += 1;
		check_map_enemy(vars);
		check_floor(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	render_window(vars);
	return (0);
}

int	key_a(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->can_move
		&& vars->map[vars->player_pos_row][vars->player_pos_column - 1] != '1')
	{
		vars->player_pos_column -= 1;
		check_map_enemy(vars);
		check_floor(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	render_window(vars);
	return (0);
}

int	key_d(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->can_move
		&& vars->map[vars->player_pos_row][vars->player_pos_column + 1] != '1')
	{
		vars->player_pos_column += 1;
		check_map_enemy(vars);
		check_floor(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	render_window(vars);
	return (0);
}
