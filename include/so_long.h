/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:04:43 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/05 15:53:32 by amanjon-         ###   ########.fr       */
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
# define CLOSE  17 // close red cross

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
    int height;
    int weidth;
}   t_map;

typedef struct s_game 
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	map;
	int 	keycode;
}	t_game;


/* -------- FUNCTIONS -------- */
int		main(int argc, char **argv);
int		ft_close_red_cross (t_game *game);
/* int		key_hook(int keycode, t_game *game); */
void	key_press(int keycode, t_game *game);



#endif
