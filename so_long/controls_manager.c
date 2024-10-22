/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:43 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 16:05:31 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	key_esc(int keycode, t_vars *vars)
{
	keycode = XK_Escape;
	printf("(ESC) ¡Bye! :D\n");
	free_resources(vars);
	exit(1);
}

int	key_w(int keycode, t_vars *vars)
{
	keycode = XK_w;
	if (vars->can_move && vars->map[vars->player_pos_row
			- 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row -= 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}

int	key_s(int keycode, t_vars *vars)
{
	keycode = XK_s;
	if (vars->can_move && vars->map[vars->player_pos_row
			+ 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row += 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}

int	key_a(int keycode, t_vars *vars)
{
	keycode = XK_a;
	if (vars->can_move
		&& vars->map[vars->player_pos_row][vars->player_pos_column - 1] != '1')
	{
		vars->player_pos_column -= 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}

int	key_d(int keycode, t_vars *vars)
{
	keycode = XK_d;
	if (vars->can_move
		&& vars->map[vars->player_pos_row][vars->player_pos_column + 1] != '1')
	{
		vars->player_pos_column += 1;
		check_floor(vars);
		check_map_enemy(vars);
		render_window(vars);
		return (1);
	}
	check_map_enemy(vars);
	check_floor(vars);
	render_window(vars);
	return (0);
}
