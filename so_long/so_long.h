/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvidal-t <jvidal-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:42:01 by jvidal-t          #+#    #+#             */
/*   Updated: 2024/10/22 14:03:06 by jvidal-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFF_SIZE 4096
# define SPRITE_SIZE 32
# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

# include "mlx.h"
# include "mlx_int.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	// MISC
	int		fd;
	int		bytes_read;
	int		map_is_valid;
	char	*buffer;
	// MATRIX
	char	**map;
	// VOID PTRS
	void	*player_ptr;
	void	*floor_ptr;
	void	*obstacle_ptr;
	void	*collectable_ptr;
	void	*endtile_ptr;
	void	*endtile_end_ptr;
	void	*enemy_ptr;
	// CHAR PTRS
	char	*map_path;
	char	*player_path;
	char	*floor_path;
	char	*obstacle_path;
	char	*collectable_path;
	char	*endtile_path;
	char	*endtile_end_path;
	char	*enemy_path;
	// IMG DATA
	int		img_width;
	int		img_height;
	// MAP DATA
	int		map_columns;
	int		map_rows;
	// PLAYER POS DATA
	int		player_pos_column;
	int		player_pos_row;
	// ENEMY POS DATA
	int		enemy_pos_column;
	int		enemy_pos_row;
	int		enemy_exists;
	// EP DATA
	int		start_pos_column;
	int		start_pos_row;
	int		end_pos_column;
	int		end_pos_row;
	// COLLECTABLES N
	int		n_collectables;
	int		collectables;
	// PlAYER CAN MOVE
	int		can_move;
	int		moves;
	// NUMBERS
	void	*n_1;
	void	*n_2;
	void	*n_3;
	void	*n_4;
	void	*n_5;
	void	*n_6;
	void	*n_7;
	void	*n_8;
	void	*n_9;
	void	*n_0;
}			t_vars;

void		free_resources(t_vars *vars);
int			close_window(t_vars *vars);
int			error_print(char *str);
void		init_vars(t_vars *vars);
int			check_map_name(char *argv);
char		*ft_strappend(char *s1, char *s2);
int			set_matrix(t_vars *vars);
void		calculate_map_size(t_vars *vars);
void		render_moves(t_vars *vars, char *str);
void		render_units(t_vars *vars, char c);
void		render_tens(t_vars *vars, char c);
void		render_hundreds(t_vars *vars, char c);
void		render_window(t_vars *vars);
int			check_map(t_vars *vars);
int			check_enemy(t_vars *vars);
void		flood_fill(t_vars *vars);
int			check_flood(t_vars *vars);
void		init_sprites(t_vars *vars);
int			check_pe(t_vars *vars);
// controls
int			key_esc(int keycode, t_vars *vars);
int			key_w(int keycode, t_vars *vars);
int			key_s(int keycode, t_vars *vars);
int			key_a(int keycode, t_vars *vars);
int			key_d(int keycode, t_vars *vars);
void		check_map_enemy(t_vars *vars);
int			check_floor(t_vars *vars);

#endif