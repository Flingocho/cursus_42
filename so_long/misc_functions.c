/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:47 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 12:33:11 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

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

int	check_floor_2(t_vars *vars)
{
	if (vars->player_pos_column == vars->enemy_pos_column
		&& vars->player_pos_row == vars->enemy_pos_row)
	{
		vars->map[vars->player_pos_row][vars->player_pos_column] = 'k';
		mlx_destroy_image(vars->mlx, vars->player_ptr);
		vars->player_path = vars->enemy_path;
		vars->player_ptr = mlx_xpm_file_to_image(vars->mlx, vars->player_path,
				&vars->img_width, &vars->img_height);
		vars->can_move = 0;
		return (1);
	}
	return (0);
}

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
	check_floor_2(vars);
	return (0);
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}

void	render_moves(t_vars *vars, char *str)
{
	int	len;

	len = ft_strlen(str);
	render_units(vars, str[len - 1]);
	if (len > 1)
		render_tens(vars, str[len - 2]);
	if (len > 2)
		render_hundreds(vars, str[len - 3]);
}
