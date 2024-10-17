/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:54:47 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/17 02:39:09 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	check_perimeter(t_vars *vars)
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
	ft_printf("i = %d, j = %d, rows = %d, columns = %d\n", i, j, vars->map_rows,
		vars->map_columns);
	if (i == vars->map_columns && j == vars->map_rows)
		return (1);
	return (-1);
}

int	check_c(t_vars *vars)
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

int	check_pe(t_vars *vars)
{
	int	i[2];
	int	e;
	int	p;

	i[0] = 0;
	e = 0;
	p = 0;
	while (vars->map[i[0]])
	{
		i[1] = 0;
		while (i[1] < vars->map_columns)
		{
			if ((vars->map[i[0]][i[1]] == 'e' || vars->map[i[0]][i[1]] == 'E'))
				e += 1;
			if ((vars->map[i[0]][i[1]] == 'p' || vars->map[i[0]][i[1]] == 'P'))
				p += 1;
			i[1]++;
		}
		i[0]++;
	}
	if (e == 1 && p == 1)
		return (1);
	return (-1);
}

void	set_pe(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("DENTRO\n");
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
				ft_printf("i = %d j = %d\n",i, j);
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
