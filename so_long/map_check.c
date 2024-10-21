/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:16:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/21 19:50:45 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

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

int	check_map_name(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	while (argv[i] >= 0)
		if (argv[i--] == '.')
			if (ft_strncmp(&argv[i + 1], ".ber", ft_strlen(&argv[i + 1])
					+ 4) == 0)
				return (1);
	return (-1);
}

int	alloc_buffer(t_vars *vars)
{
	int	i;

	i = 0;
	vars->buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!vars->buffer)
		return (-1);
	vars->fd = open(vars->map_path, O_RDONLY);
	if (vars->fd < 0)
		return (-1);
	vars->bytes_read = read(vars->fd, vars->buffer, BUFF_SIZE);
	if (vars->bytes_read == -1)
		return (-1);
	vars->buffer[vars->bytes_read] = '\0';
	close(vars->fd);
	while (vars->buffer[i++] != '\0')
		if (vars->buffer[i] == '\0' && i <= vars->bytes_read)
			return (1);
	return (-1);
}

int	set_matrix(t_vars *vars)
{
	if (alloc_buffer(vars) == -1)
	{
		close(vars->fd);
		if (vars->buffer)
			free(vars->buffer);
		return (-1);
	}
	ft_printf("%s\n", vars->buffer);
	vars->map = ft_split(vars->buffer, '\n');
	free(vars->buffer);
	return (1);
}

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
	ft_printf("counter = %d\n\r", vars->moves);
	return (0);
}

void	calculate_map_size(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_columns = ft_strlen(vars->map[0]);
	while (vars->map[i])
		i++;
	vars->map_rows = i;
}

int	check_enemy(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_rows)
	{
		j = 0;
		while (j < vars->map_columns)
		{
			if (vars->map[i][j] == 'K' || vars->map[i][j] == 'k')
			{
				vars->enemy_pos_column = j;
				vars->enemy_pos_row = i;
				vars->enemy_exists = 1;
			}
			j++;
		}
		i++;
	}
	if (vars->enemy_pos_column > 0 || vars->enemy_pos_row > 0)
		return (1);
	return (-1);
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
	if (check_flood(vars) == -1)
		return (error_print("Flood fill error.\n"));
	init_sprites(vars);
	render_window(vars);
	return (0);
}
