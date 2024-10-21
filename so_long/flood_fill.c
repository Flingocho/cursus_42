/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:11:02 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/21 12:16:32 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	check_flood(t_vars *vars)
{
	if (vars->start_pos_row < 0 || vars->start_pos_column < 0
		|| vars->start_pos_column >= vars->map_columns || vars->start_pos_row >= vars->map_rows)
		return (-1);
	flood_fill(vars);
	if (vars->map[vars->end_pos_row][vars->end_pos_column] == 'X' && vars->n_collectables == 0)
		return (1);
	return (-1);
}

static void	f_fill(t_vars *vars, char *target, int row, int col)
{
	if (row < 0 || col < 0 || row >= vars->map_rows || col >= vars->map_columns)
		return ;
	if (vars->map[row][col] == '2' || (vars->map[row][col] != target[0]
			&& (vars->map[row][col] != target[1])
			&& (vars->map[row][col] != target[2])))
		return ;
	if (vars->map[row][col] == 'C')
	{
		vars->n_collectables -= 1;
		vars->map[row][col] = '@';
	}
	else if (vars->map[row][col] == 'E')
		vars->map[row][col] = 'X';
	else if (vars->map[row][col] == 'K')
		vars->map[row][col] = 'k';
	else
		vars->map[row][col] = ' ';
	f_fill(vars, target, row - 1, col);
	f_fill(vars, target, row + 1, col);
	f_fill(vars, target, row, col - 1);
	f_fill(vars, target, row, col + 1);
}

void	flood_fill(t_vars *vars)
{
	char	target[3];

	target[0] = '0';
	target[1] = 'C';
	target[2] = 'E';
	f_fill(vars, target, vars->start_pos_row, vars->start_pos_column);
}

