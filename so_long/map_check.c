/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:16:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/17 00:46:00 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

// PUT YOUR FUCKING STRCM HERE U STUPID
int	check_map_name(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	while (argv[i] >= 0)
		if (argv[i--] == '.')
			return (strcmp(&argv[i + 1], ".ber"));
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
		return (error_print("Eror allocation."));
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
	ft_printf("counter = %d\n", vars->moves);
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
	if (check_flood(vars) == -1)
		return (error_print("Flood fill error.\n"));
	init_sprites(vars);
	render_window(vars);
	return (0);
}
