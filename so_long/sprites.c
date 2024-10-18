/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:44:12 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/17 02:20:38 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

// PLACEHOLDER
static void	get_sprites_info(t_vars *vars)
{
	vars->obstacle_path = "sprites/obstacle.xpm";
	vars->player_path = "sprites/player.xpm";
	vars->collectable_path = "sprites/collectable.xpm";
	vars->endtile_path = "sprites/end.xpm";
	vars->floor_path = "sprites/floor.xpm";
	vars->endtile_end_path = "sprites/end_end.xpm";
	vars->img_width = SPRITE_SIZE;
	vars->img_height = SPRITE_SIZE;
}

void	render_number(t_vars *vars)
{
	vars->n_0 = mlx_xpm_file_to_image(vars->mlx, "sprites/0.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_1 = mlx_xpm_file_to_image(vars->mlx, "sprites/1.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_2 = mlx_xpm_file_to_image(vars->mlx, "sprites/2.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_3 = mlx_xpm_file_to_image(vars->mlx, "sprites/3.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_4 = mlx_xpm_file_to_image(vars->mlx, "sprites/4.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_5 = mlx_xpm_file_to_image(vars->mlx, "sprites/5.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_6 = mlx_xpm_file_to_image(vars->mlx, "sprites/6.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_7 = mlx_xpm_file_to_image(vars->mlx, "sprites/7.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_8 = mlx_xpm_file_to_image(vars->mlx, "sprites/8.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_9 = mlx_xpm_file_to_image(vars->mlx, "sprites/9.xpm",
			&vars->img_width, &vars->img_height);
}

void	init_sprites(t_vars *vars)
{
	get_sprites_info(vars);
	vars->obstacle_ptr = mlx_xpm_file_to_image(vars->mlx, vars->obstacle_path,
			&vars->img_width, &vars->img_height);
	vars->player_ptr = mlx_xpm_file_to_image(vars->mlx, vars->player_path,
			&vars->img_width, &vars->img_height);
	vars->collectable_ptr = mlx_xpm_file_to_image(vars->mlx,
			vars->collectable_path, &vars->img_width, &vars->img_height);
	vars->endtile_ptr = mlx_xpm_file_to_image(vars->mlx, vars->endtile_path,
			&vars->img_width, &vars->img_height);
	vars->floor_ptr = mlx_xpm_file_to_image(vars->mlx, vars->floor_path,
			&vars->img_width, &vars->img_height);
	vars->endtile_end_ptr = mlx_xpm_file_to_image(vars->mlx,
			vars->endtile_end_path, &vars->img_width, &vars->img_height);
	render_number(vars);
	vars->player_pos_column = vars->start_pos_column;
	vars->player_pos_row = vars->start_pos_row;
	vars->can_move = 1;
	vars->moves = 0;
}

static void	put_img(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->obstacle_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	if (vars->map[y][x] == 'X')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->endtile_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	if (vars->map[y][x] == ' ')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	if (vars->map[y][x] == '@')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collectable_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	if (vars->map[y][x] == 'x')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->endtile_end_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
}

void	render_window(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_rows > i)
	{
		j = 0;
		while (vars->map_columns > j)
		{
			put_img(vars, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ptr,
		vars->player_pos_column * SPRITE_SIZE, vars->player_pos_row
		* SPRITE_SIZE);
}
