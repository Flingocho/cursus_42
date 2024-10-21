/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:38:00 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/21 20:06:41 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	move_set_1(t_vars *vars)
{
	static int	direction;

	if (vars->can_move == 1)
	{
		if (strcmp(vars->enemy_path, "sprites/enemy.xpm") == 0)
			vars->enemy_path = "sprites/enemy2.xpm";
		else
			vars->enemy_path = "sprites/enemy.xpm";
		mlx_destroy_image(vars->mlx, vars->enemy_ptr);
		vars->enemy_ptr = mlx_xpm_file_to_image(vars->mlx, vars->enemy_path,
				&vars->img_width, &vars->img_height);
		if (vars->enemy_pos_row == 1)
			direction = 0;
		if (vars->enemy_pos_row == vars->map_rows - 2)
			direction = 1;
		if (direction == 0)
			vars->enemy_pos_row += 1;
		if (direction == 1)
			vars->enemy_pos_row -= 1;
	}
	check_floor(vars);
}

void	move_set_2(t_vars *vars)
{
	static int	direction;

	if (vars->can_move == 1)
	{
		if (strcmp(vars->enemy_path, "sprites/enemy.xpm") == 0)
			vars->enemy_path = "sprites/enemy2.xpm";
		else
			vars->enemy_path = "sprites/enemy.xpm";
		mlx_destroy_image(vars->mlx, vars->enemy_ptr);
		vars->enemy_ptr = mlx_xpm_file_to_image(vars->mlx, vars->enemy_path,
				&vars->img_width, &vars->img_height);
		if (vars->enemy_pos_row == 1)
			direction = 0;
		if (vars->enemy_pos_row == vars->map_rows - 2)
			direction = 1;
		if (direction == 0)
			vars->enemy_pos_row += 1;
		if (direction == 1)
			vars->enemy_pos_row -= 1;
	}
	check_floor(vars);
}

void	move_set_3(t_vars *vars)
{
	static int	direction;

	if (vars->can_move == 1)
	{
		if (strcmp(vars->enemy_path, "sprites/enemy.xpm") == 0)
			vars->enemy_path = "sprites/enemy2.xpm";
		else
			vars->enemy_path = "sprites/enemy.xpm";
		mlx_destroy_image(vars->mlx, vars->enemy_ptr);
		vars->enemy_ptr = mlx_xpm_file_to_image(vars->mlx, vars->enemy_path,
				&vars->img_width, &vars->img_height);
		if (vars->enemy_pos_row == 6)
			direction = 0;
		if (vars->enemy_pos_row == vars->map_rows - 8)
			direction = 1;
		if (direction == 0)
			vars->enemy_pos_row += 1;
		if (direction == 1)
			vars->enemy_pos_row -= 1;
	}
	check_floor(vars);
}

void	check_map_enemy(t_vars *vars)
{
	// PUT YPUR FUCKING STRCMP
	if (ft_strncmp(vars->map_path, "maps/map.ber", ft_strlen(vars->map_path)) == 0)
		move_set_1(vars);
	if (ft_strncmp(vars->map_path, "maps/map2.ber", ft_strlen(vars->map_path)) == 0)
		move_set_2(vars);
	if (ft_strncmp(vars->map_path, "maps/map3.ber", ft_strlen(vars->map_path)) == 0)
		move_set_3(vars);
}