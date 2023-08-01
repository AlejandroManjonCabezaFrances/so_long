/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:04:43 by amanjon-          #+#    #+#             */
/*   Updated: 2023/08/01 08:59:58 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---- NEW ---- */
# include <mlx.h>
# include <fcntl.h>

/* --- LIBRARIES --- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

/* ---------------- PATH ---------------- */
# include "../libft/Libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/Gnl/include/get_next_line.h"

/* ---------------- PATH XPM ---------------- */
# define EXITON			"./xpm/exiton128.xpm"
# define EXITOFF		"./xpm/exitoff128.xpm"
# define FLOOR			"./xpm/floor128.xpm"
# define DOWN			"./xpm/player_down.xpm"
# define LEFT			"./xpm/player_left.xpm"
# define RIGHT			"./xpm/player_right.xpm"
# define UP				"./xpm/player_up.xpm"
# define WALL			"./xpm/wall128.xpm"
# define COLLECTIB		"./xpm/collectible128.xpm"

/* ----- RESOLUTIONS ----- */
# define RESOLUTION_H	128
# define RESOLUTION_W	128

/* ------- KEYS ------- */
# define KEY_PRESS		2	// ft_key_press
# define CLOSE_RED 		17	// close red cross -MASK-

# define KEY_ESC		53
# define KEY_W			13
# define KEY_S			1
# define KEY_D			2
# define KEY_A			0
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_RIGHT	124
# define ARROW_LEFT		123  

/* ----- MAP SYMBOLS ----- */
# define PLAYER_RIGHT	'P'
# define PLAYER_LEFT	'L'
# define PLAYER_UP		'U'
# define PLAYER_DOWN	'D'
# define PRE_EXIT		'E'
# define EXIT			'S'
# define COLLECTIBLE	'C'
# define WALL_GREEN		'1'
# define ROAD			'0'

/* ----- STRUCT ----- */
typedef struct s_map
{
	char		**create_maps;
	char		**cpy_create_maps;
	int			height;
	int			width;
	int			fire_count;
	int			fire_total;
	char		*str_line;
	void		*exit_on;
	void		*exit_off;
	void		*floor;
	void		*wall;
	void		*collectible;
}	t_map;

typedef struct s_player
{
	void		*player_down;
	void		*player_left;
	void		*player_right;
	void		*player_up;
	int			steps;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			keycode;
	t_player	player;
	t_map		map;
}	t_game;

/* -------- FUNCTIONS -------- */
char	*ft_read_map(char *filename, t_game *game);
int		ft_missing_some_ingredients(char ingredient);
int		ft_key_press(int keycode, t_game *game);
int		ft_check_input(int argc, char **argv);
int		ft_close_red_cross(t_game *game);
int		ft_check_walls_2(t_game *game);
int		ft_check_walls(t_game *game);
int		main(int argc, char **argv);
int		ft_check_path(t_game *game);
int		ft_check_map(t_game *game);
void	ft_check_map_with_break_line_end_middle(t_game *game);
void	ft_check_map_with_break_line_start(char *line);
void	ft_player_rigth(t_game *game, int h, int w);
void	ft_player_down(t_game *game, int h, int w);
void	ft_player_left(t_game *game, int h, int w);
void	ft_count_total_collectibles(t_game *game);
void	ft_print_map3(t_game *game, int h, int w);
void	ft_cpy_map(char *read_map, t_game *game);
void	ft_player_up(t_game *game, int h, int w);
void	ft_cpy_map_for_floodfill(t_game *game);
void	ft_create_images(t_game *game);
void	ft_check_xpm(void *xpm_save);
void	ft_find_player(t_game *game);
void	ft_print_map(t_game *game);
void	ft_open_exit(t_game *game);
void	ft_key_w(t_game *game);
void	ft_key_s(t_game *game);
void	ft_key_a(t_game *game);
void	ft_key_d(t_game *game);
void	ft_error(char *sms);
void	ft_free(char **str);

#endif
