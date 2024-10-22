/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:20:55 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 14:13:41 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static int	check_perimeter(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((vars->map[0][i] == '1' && vars->map[vars->map_rows - 1][i] == '1'))
		i++;
	while (vars->map[j] && (vars->map[j][0] == '1'
		&& vars->map[j][vars->map_columns - 1] == '1'))
		j++;
	if (i == vars->map_columns && j == vars->map_rows)
		return (1);
	return (-1);
}

static int	check_invalid_char(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_rows)
	{
		j = 0;
		while (j < vars->map_columns)
		{
			if (vars->map[i][j] != '1' && vars->map[i][j] != '0'
				&& vars->map[i][j] != 'P' && vars->map[i][j] != 'E'
				&& vars->map[i][j] != 'C' && vars->map[i][j] != 'X'
				&& vars->map[i][j] != 'C' && vars->map[i][j] != 'K')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_c(t_vars *vars)
{
	int	i;
	int	j;

	vars->n_collectables = 0;
	i = 0;
	while (i < vars->map_rows)
	{
		j = 0;
		while (j < vars->map_columns)
		{
			if (vars->map[i][j] == 'c' || vars->map[i][j] == 'C')
				vars->n_collectables += 1;
			j++;
		}
		i++;
	}
	if (vars->n_collectables > 0)
	{
		vars->collectables = vars->n_collectables;
		return (1);
	}
	return (-1);
}

static void	set_pe(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_rows)
	{
		j = 0;
		while (j < vars->map_columns)
		{
			if (vars->map[i][j] == 'P')
			{
				vars->start_pos_column = j;
				vars->start_pos_row = i;
				vars->map[i][j] = '0';
			}
			if (vars->map[i][j] == 'E')
			{
				vars->end_pos_column = j;
				vars->end_pos_row = i;
			}
			j++;
		}
		i++;
	}
}

int	check_map(t_vars *vars)
{
	if (check_perimeter(vars) == -1)
		return (error_print("Perimeter error.\n"));
	if (check_invalid_char(vars) == -1)
		return (error_print("Invalid char error.\n"));
	if (check_c(vars) == -1)
		return (error_print("Collectables error.\n"));
	if (check_pe(vars) == -1)
		return (error_print("Player/Exit error.\n"));
	set_pe(vars);
	if (check_enemy(vars) == -1)
		ft_printf("This map has no enemies! :D\n");
	if	(check_enemy(vars) == -2)
		return (error_print("Too many enemies.\n"));
	if (check_flood(vars) == -1)
		return (error_print("Flood fill error.\n"));
	init_sprites(vars);
	render_window(vars);
	return (0);
}
