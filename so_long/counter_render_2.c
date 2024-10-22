/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_render_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:11:36 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 12:26:44 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	render_hundreds_2(t_vars *vars, char c)
{
	if (c == '5')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_5,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '6')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_6,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '7')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_7,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '8')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_8,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '9')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_9,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
}

void	render_hundreds(t_vars *vars, char c)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_0,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_1,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '2')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_2,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '3')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_3,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	if (c == '4')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_4,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
	render_hundreds_2(vars, c);
}
