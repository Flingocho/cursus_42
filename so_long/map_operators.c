/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:02:39 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 11:55:03 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static int	alloc_buffer(t_vars *vars)
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

void	calculate_map_size(t_vars *vars)
{
	int	i;

	i = 0;
	vars->map_columns = ft_strlen(vars->map[0]);
	while (vars->map[i])
		i++;
	vars->map_rows = i;
}
