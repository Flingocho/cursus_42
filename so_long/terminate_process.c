/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:57:42 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 15:20:10 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	error_print(char *str)
{
	ft_printf("\nError\n");
	ft_printf("%s\n", str);
	return (-1);
}

int	close_window(t_vars *vars)
{
	printf("Window closed. Exiting...\n\n");
	free_resources(vars);
	exit(0);
	return (0);
}

static void	free_resources_3(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

static void	free_resources_2(t_vars *vars)
{
	if (vars->n_0)
		mlx_destroy_image(vars->mlx, vars->n_0);
	if (vars->n_1)
		mlx_destroy_image(vars->mlx, vars->n_1);
	if (vars->n_2)
		mlx_destroy_image(vars->mlx, vars->n_2);
	if (vars->n_3)
		mlx_destroy_image(vars->mlx, vars->n_3);
	if (vars->n_4)
		mlx_destroy_image(vars->mlx, vars->n_4);
	if (vars->n_5)
		mlx_destroy_image(vars->mlx, vars->n_5);
	if (vars->n_6)
		mlx_destroy_image(vars->mlx, vars->n_6);
	if (vars->n_7)
		mlx_destroy_image(vars->mlx, vars->n_7);
	if (vars->n_8)
		mlx_destroy_image(vars->mlx, vars->n_8);
	if (vars->n_9)
		mlx_destroy_image(vars->mlx, vars->n_9);
	if (vars->enemy_ptr)
		mlx_destroy_image(vars->mlx, vars->enemy_ptr);
	if (vars->map_path)
		free(vars->map_path);
	free_resources_3(vars);
}

void	free_resources(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (vars->map[i])
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
	free_resources_2(vars);
}
