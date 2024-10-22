/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:41:48 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 15:19:48 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	char	*str;

	if (keycode == XK_Escape)
		vars->moves += key_esc(keycode, vars);
	if (keycode == XK_w)
		vars->moves += key_w(keycode, vars);
	if (keycode == XK_s)
		vars->moves += key_s(keycode, vars);
	if (keycode == XK_a)
		vars->moves += key_a(keycode, vars);
	if (keycode == XK_d)
		vars->moves += key_d(keycode, vars);
	if (vars->moves >= 999)
		vars->moves = 999;
	str = ft_itoa(vars->moves);
	render_moves(vars, str);
	free(str);
	ft_printf("counter = %d\n", vars->moves);
	return (0);
}

int	init_process(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_columns * 32,
			(vars->map_rows + 1) * 32, "SO_LONG!");
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	if (check_map(vars) == -1)
	{
		error_print("Aborting :(\n");
		return (close_window(vars));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	if (!(argc == 2 && check_map_name(argv[1]) == 1))
	{
		error_print("Invalid map name, opening default.\n");
		vars.map_path = ft_strdup("maps/map.ber");
		if (!vars.map_path)
		{
			error_print("path error");
			free_resources(&vars);
		}
	}
	else
		vars.map_path = ft_strappend("maps/", argv[1]);
	if (!(set_matrix(&vars) == 1))
	{
		error_print("Map error.\n");
		close_window(&vars);
	}
	calculate_map_size(&vars);
	init_process(&vars);
	mlx_loop(vars.mlx);
	free_resources(&vars);
	return (0);
}
