/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:47:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/17 01:40:35 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2 && check_map_name(argv[1]) == 0)
		vars.map_path = argv[1];
	else
		vars.map_path = "map.ber";
	if (set_matrix(&vars) == 1)
		ft_printf("WE CHILLING\n");
	calculate_map_size(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_columns * 32, vars.map_rows
			* 32, "SO_LONG!");
	mlx_key_hook(vars.win, key_hook, &vars);
	check_map(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
