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
		mlx_destroy_image(vars->mlx, vars->player_ptr);
		vars->player_path = vars->endtile_end_path;
		vars->player_ptr = mlx_xpm_file_to_image(vars->mlx, vars->player_path,
				&vars->img_width, &vars->img_height);
		vars->can_move = 0;
		return (1);
	}
	return (0);
}

void	free_resources(t_vars *vars)
{
	int i;

	i = 0;
	if (vars->map)
	{
		while (vars->map[i] != NULL)
			free(vars->map[i++]);
		free(vars->map);
	}
	if (vars->player_ptr)
		mlx_destroy_image(vars->mlx, vars->player_ptr);
	if (vars->floor_ptr)
		mlx_destroy_image(vars->mlx, vars->floor_ptr);
	if (vars->obstacle_ptr)
		mlx_destroy_image(vars->mlx, vars->obstacle_ptr);
	if (vars->collectable_ptr)
		mlx_destroy_image(vars->mlx, vars->collectable_ptr);
	if (vars->endtile_ptr)
		mlx_destroy_image(vars->mlx, vars->endtile_ptr);
	if (vars->endtile_end_ptr)
		mlx_destroy_image(vars->mlx, vars->endtile_end_ptr);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->units)
		mlx_destroy_image(vars->mlx, vars->units);
	if (vars->tens)
		mlx_destroy_image(vars->mlx, vars->tens);
	if (vars->hundreds)
		mlx_destroy_image(vars->mlx, vars->hundreds);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}