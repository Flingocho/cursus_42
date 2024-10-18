
#include "libft.h"
#include "so_long.h"


void	render_units(t_vars *vars, char c)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_0,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_1,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '2')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_2,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '3')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_3,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '4')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_4,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '5')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_5,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '6')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_6,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '7')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_7,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '8')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_8,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '9')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_9,
			(vars->map_columns - 1) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
}

void	render_tens(t_vars *vars, char c)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_0,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_1,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '2')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_2,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '3')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_3,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '4')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_4,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '5')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_5,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '6')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_6,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '7')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_7,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '8')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_8,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '9')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_9,
			(vars->map_columns - 2) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
}

void	render_hundreds(t_vars *vars, char c)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_0,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->n_1,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '2')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_2,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '3')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_3,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '4')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_4,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '5')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_5,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '6')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_6,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '7')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_7,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '8')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_8,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
    if (c == '9')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->n_9,
			(vars->map_columns - 3) * SPRITE_SIZE, (vars->map_rows)
			* SPRITE_SIZE);
}

void	render_moves(t_vars *vars, char *str)
{
	int	len;

	len = ft_strlen(str);
	render_units(vars, str[len - 1]);
	if(len > 1)
		render_tens(vars, str[len - 2]);
	if(len > 2)
		render_hundreds(vars, str[len - 3]);
}
