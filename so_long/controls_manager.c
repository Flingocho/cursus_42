/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:43 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/17 01:20:53 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	key_esc(int keycode, t_vars *vars)
{
	printf("(ESC) ¡Bye! :D\n");
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(1);
}

int	key_w(int keycode, t_vars *vars)
{
	printf("Pressed: w\n");
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->map[vars->player_pos_row - 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row -= 1;
		check_floor(vars);
	}
	render_window(vars);
	return (1);
}

int	key_s(int keycode, t_vars *vars)
{
	ft_printf("Pressed: s\n");
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->map[vars->player_pos_row + 1][vars->player_pos_column] != '1')
	{
		vars->player_pos_row += 1;
		check_floor(vars);
	}
	render_window(vars);
	return (1);
}

int	key_a(int keycode, t_vars *vars)
{
	{
		ft_printf("Pressed: a\n");
		mlx_clear_window(vars->mlx, vars->win);
		if (vars->map[vars->player_pos_row][vars->player_pos_column - 1] != '1')
		{
			vars->player_pos_column -= 1;
			check_floor(vars);
		}
		render_window(vars);
		return (1);
	}
}

int	key_d(int keycode, t_vars *vars)
{
	ft_printf("Pressed: a\n");
	mlx_clear_window(vars->mlx, vars->win);
	if (vars->map[vars->player_pos_row][vars->player_pos_column + 1] != '1')
	{
		vars->player_pos_column += 1;
		check_floor(vars);
	}
	render_window(vars);
	return (1);
}
