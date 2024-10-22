/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:00:46 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 15:31:39 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	get_sprites_info(t_vars *vars)
{
	vars->obstacle_path = "textures/obstacle.xpm";
	vars->player_path = "textures/player.xpm";
	vars->collectable_path = "textures/collectable.xpm";
	vars->endtile_path = "textures/end.xpm";
	vars->floor_path = "textures/floor.xpm";
	vars->endtile_end_path = "textures/end_end.xpm";
	vars->enemy_path = "textures/enemy.xpm";
	vars->img_width = SPRITE_SIZE;
	vars->img_height = SPRITE_SIZE;
}

static void	render_number(t_vars *vars)
{
	vars->n_0 = mlx_xpm_file_to_image(vars->mlx, "textures/0.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_1 = mlx_xpm_file_to_image(vars->mlx, "textures/1.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_2 = mlx_xpm_file_to_image(vars->mlx, "textures/2.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_3 = mlx_xpm_file_to_image(vars->mlx, "textures/3.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_4 = mlx_xpm_file_to_image(vars->mlx, "textures/4.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_5 = mlx_xpm_file_to_image(vars->mlx, "textures/5.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_6 = mlx_xpm_file_to_image(vars->mlx, "textures/6.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_7 = mlx_xpm_file_to_image(vars->mlx, "textures/7.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_8 = mlx_xpm_file_to_image(vars->mlx, "textures/8.xpm",
			&vars->img_width, &vars->img_height);
	vars->n_9 = mlx_xpm_file_to_image(vars->mlx, "textures/9.xpm",
			&vars->img_width, &vars->img_height);
}

static void	init_vars_2(t_vars *vars)
{
	vars->win = NULL;
	vars->fd = 0;
	vars->bytes_read = 0;
	vars->map_is_valid = 0;
	vars->buffer = NULL;
	vars->player_pos_column = 0;
	vars->player_pos_row = 0;
	vars->end_pos_column = 0;
	vars->end_pos_row = 0;
	vars->moves = 0;
	vars->n_0 = NULL;
	vars->n_1 = NULL;
	vars->n_2 = NULL;
	vars->n_3 = NULL;
	vars->n_4 = NULL;
	vars->n_5 = NULL;
	vars->n_6 = NULL;
	vars->n_7 = NULL;
	vars->n_8 = NULL;
	vars->n_9 = NULL;
	vars->enemy_ptr = NULL;
	vars->enemy_ptr = NULL;
	vars->enemy_pos_column = 0;
	vars->enemy_pos_row = 0;
	vars->enemy_exists = 0;
}

void	init_vars(t_vars *vars)
{
	vars->map = NULL;
	vars->player_ptr = NULL;
	vars->floor_ptr = NULL;
	vars->obstacle_ptr = NULL;
	vars->collectable_ptr = NULL;
	vars->endtile_ptr = NULL;
	vars->endtile_end_ptr = NULL;
	vars->map_path = NULL;
	vars->player_path = NULL;
	vars->floor_path = NULL;
	vars->obstacle_path = NULL;
	vars->collectable_path = NULL;
	vars->endtile_path = NULL;
	vars->endtile_end_path = NULL;
	vars->img_width = 32;
	vars->img_height = 32;
	vars->map_columns = 0;
	vars->map_rows = 0;
	vars->start_pos_column = 0;
	vars->start_pos_row = 0;
	vars->n_collectables = 0;
	vars->collectables = 0;
	vars->can_move = 1;
	vars->mlx = NULL;
	init_vars_2(vars);
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
	vars->enemy_ptr = mlx_xpm_file_to_image(vars->mlx, vars->enemy_path,
			&vars->img_width, &vars->img_height);
	render_number(vars);
	vars->player_pos_column = vars->start_pos_column;
	vars->player_pos_row = vars->start_pos_row;
	vars->can_move = 1;
	vars->moves = 0;
}
