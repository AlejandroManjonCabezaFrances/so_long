/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:04:43 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/14 14:26:46 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---- NEW ---- */
# include <mlx.h>
# include <fcntl.h>

/* -- LIBRARIES -- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

/* --------------- PATH --------------- */
# include "../libft/Libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/Gnl/include/get_next_line.h"

/* ---- KEYS ---- */
# define CLOSE  17 // close red cross -MASK-

# define KEY_ESC		53
# define KEY_W			13
# define KEY_S			1
# define KEY_D			2
# define KEY_A			0
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_RIGHT	124
# define ARROW_LEFT		123  

/* ---- MAP SYMBOLS ---- */
# define PLAYER			'P'
# define EXIT			'E'
# define COLLECTIBLE	'C'
# define WALL			'1'
# define ROAD			'0'

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

/* ----- STRUCT ----- */
typedef struct s_map
{
	char	**create_maps;
    int		height;
    int		width;
	char	*str_line;
	void	*door;
	void	*floor;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*wall;
	void	*weapon;
}   t_map;

typedef struct s_game 
{
	void	*mlx;
	void	*win;
	t_map	map;
	int 	keycode;
}	t_game;

/* -------- FUNCTIONS -------- */
int		main(int argc, char **argv);
int		ft_close_red_cross (t_game *game);
/* int		key_hook(int keycode, t_game *game); */
/* void	key_press(int keycode, t_game *game); */
char	*ft_strdup_no_new_line(char	*s1);
char	*ft_strjoin_no_new_line(char *s1, char *s2);
void	ft_read_map2(char *filename, t_game *game);
int		ft_cpy_map2(t_game *game);
void	ft_create_images2(t_game *game);
void	ft_put_images2(t_game *game);
void	ft_read_map(char *filename, t_game *game);

#endif
