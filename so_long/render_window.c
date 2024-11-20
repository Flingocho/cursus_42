/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:19:00 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 12:36:00 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	put_img(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->obstacle_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	if (vars->map[y][x] == 'X')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->endtile_ptr, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	if (vars->map[y][x] == ' ' || vars->map[y][x] == 'K')
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
	i = 0;
	while (i < vars->map_columns)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_ptr, (i++)
			* SPRITE_SIZE, (vars->map_rows) * SPRITE_SIZE);
	if (vars->enemy_exists == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy_ptr,
			vars->enemy_pos_column * SPRITE_SIZE, vars->enemy_pos_row
			* SPRITE_SIZE);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ptr,
		vars->player_pos_column * SPRITE_SIZE, vars->player_pos_row
		* SPRITE_SIZE);
}
