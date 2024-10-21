/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:47:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/21 15:12:20 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	error_print(char *str)
{
	ft_printf("%s\n", str);
	return (-1);
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
	vars->enemy_pos_row  = 0;
	vars->enemy_exists = 0;
	vars->win_buffer = NULL;
}

int close_window(t_vars *vars)
{
    printf("Window closed. Exiting...\n");
    free_resources(vars);
    exit(0);
    return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	if (!(argc == 2 && check_map_name(argv[1]) == 0))
	{
		error_print("Invalid map name, opening default.\n");
		vars.map_path = "map.ber";
	}
	else
		vars.map_path = argv[1];
	if (!(set_matrix(&vars) == 1))
		return (error_print("Map error.\n"));
	calculate_map_size(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_columns * 32, (vars.map_rows
				+ 1) * 32, "SO_LONG!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_do_key_autorepeaton(vars.mlx);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	if (check_map(&vars) == -1)
		return (error_print("Aborting\n"));
	mlx_loop(vars.mlx);
	free_resources(&vars);
	return (0);
}
