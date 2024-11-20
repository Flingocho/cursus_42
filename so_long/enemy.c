/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:24:24 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 16:08:20 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	move_set_1(t_vars *vars)
{
	static int	direction;

	if (vars->can_move == 1)
	{
		if (strcmp(vars->enemy_path, "textures/enemy.xpm") == 0)
			vars->enemy_path = "textures/enemy2.xpm";
		else
			vars->enemy_path = "textures/enemy.xpm";
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
}

static void	move_set_2(t_vars *vars)
{
	static int	direction;

	if (vars->can_move == 1)
	{
		if (strcmp(vars->enemy_path, "textures/enemy.xpm") == 0)
			vars->enemy_path = "textures/enemy2.xpm";
		else
			vars->enemy_path = "textures/enemy.xpm";
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
}

static void	move_set_3(t_vars *vars)
{
	static int	direction;

	if (vars->can_move == 1)
	{
		if (strcmp(vars->enemy_path, "textures/enemy.xpm") == 0)
			vars->enemy_path = "textures/enemy2.xpm";
		else
			vars->enemy_path = "textures/enemy.xpm";
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
}

void	check_map_enemy(t_vars *vars)
{
	if (ft_strncmp(vars->map_path, "maps/map.ber",
			ft_strlen(vars->map_path)) == 0)
		move_set_1(vars);
	if (ft_strncmp(vars->map_path, "maps/map2.ber",
			ft_strlen(vars->map_path)) == 0)
		move_set_2(vars);
	if (ft_strncmp(vars->map_path, "maps/map3.ber",
			ft_strlen(vars->map_path)) == 0)
		move_set_3(vars);
}

int	check_enemy(t_vars *vars)
{
	int	i[3];

	i[0] = 0;
	i[2] = 0;
	while (i[0] < vars->map_rows)
	{
		i[1] = 0;
		while (i[1] < vars->map_columns)
		{
			if (vars->map[i[0]][i[1]] == 'K')
			{
				vars->enemy_pos_column = i[1];
				vars->enemy_pos_row = i[0];
				vars->enemy_exists = 1;
				i[2] += 1;
			}
			i[1]++;
		}
		i[0]++;
	}
	if (i[2] > 1)
		return (-2);
	if (vars->enemy_pos_column > 0 || vars->enemy_pos_row > 0)
		return (1);
	return (-1);
}
