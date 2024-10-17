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

int	set_matrix(t_vars *vars)
{
	vars->fd = open(vars->map_path, O_RDONLY);
	if (vars->fd < 0)
		return (-1);
	vars->bytes_read = read(vars->fd, vars->buffer, BUFF_SIZE);
	if (vars->bytes_read > 0)
		vars->buffer[vars->bytes_read] = '\0';
	if (vars->bytes_read == -1)
		return (-1);
	close(vars->fd);
	ft_printf("%s\n", vars->buffer);
	vars->map = ft_split(vars->buffer, '\n');
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	int static	counter;
	char		*str;

	if (keycode == XK_Escape)
		counter += key_esc(keycode, vars);
	if (keycode == XK_w)
		counter += key_w(keycode, vars);
	if (keycode == XK_s)
		counter += key_s(keycode, vars);
	if (keycode == XK_a)
		counter += key_a(keycode, vars);
	if (keycode == XK_d)
		counter += key_d(keycode, vars);
	str = ft_itoa(counter);
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0x00FF0000, str);
	ft_printf("counter = %d\n", counter);
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
	ft_printf("%d is the number of columns!\n", vars->map_columns);
	ft_printf("%d is the number of rows!\n\n", vars->map_rows);
}

int	check_map(t_vars *vars)
{
	check_perimeter(vars);
	check_c(vars);
	check_pe(vars);
	set_pe(vars);
	check_flood(vars);
	init_sprites(vars);
	render_window(vars);
	return (0);
}
