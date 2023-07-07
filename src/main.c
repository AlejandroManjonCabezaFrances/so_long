/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:02:10 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/07 14:19:23 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

/* typedef struct s_map
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
}	t_game; */

/* void	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (keycode == 'W' || keycode == ARROW_UP)
		key_w(game);
	else if (keycode == 'S' || keycode == ARROW_DOWN)
		key_s(game);
	else if (keycode == 'A' || keycode == ARROW_LEFT)
		key_a(game);
	else if (keycode == 'D' || keycode == ARROW_RIGHT)
		key_d(game);
} */

int	ft_close_red_cross (t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

/* int key_hook(int keycode, t_game *game)
{
	printf("Hello from key_hook!\n");
	return (0);
} */

int	main(int argc, char **argv)
{
	t_game	game;
	
	game.map.height = 10 * 110;
	game.map.weidth = 10 * 110;
	if(argc == 0 || *argv == 0)
		return (0);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.weidth, game.map.height, "----SO LONG----");
	
	
	game.img = mlx_xpm_file_to_image(game.mlx, "./xpm/door.xpm", &game.map.height, &game.map.weidth);
	game.img2 = mlx_xpm_file_to_image(game.mlx, "./xpm/floor2.xpm", &game.map.height, &game.map.weidth);
	game.img3 = mlx_xpm_file_to_image(game.mlx, "./xpm/player_down.xpm", &game.map.height, &game.map.weidth);
	game.img4 = mlx_xpm_file_to_image(game.mlx, "./xpm/player_left.xpm", &game.map.height, &game.map.weidth);
	game.img5 = mlx_xpm_file_to_image(game.mlx, "./xpm/player_right.xpm", &game.map.height, &game.map.weidth);
	game.img6 = mlx_xpm_file_to_image(game.mlx, "./xpm/player_up.xpm", &game.map.height, &game.map.weidth);
	game.img7 = mlx_xpm_file_to_image(game.mlx, "./xpm/wall.xpm", &game.map.height, &game.map.weidth);
	game.img8 = mlx_xpm_file_to_image(game.mlx, "./xpm/weapon.xpm", &game.map.height, &game.map.weidth);
	
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img2, 512, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img3, 256, 256);
	mlx_put_image_to_window(game.mlx, game.win, game.img4, 512, 512);
	mlx_put_image_to_window(game.mlx, game.win, game.img5, 720, 720);
	mlx_put_image_to_window(game.mlx, game.win, game.img6, 512, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img7, 850, 850);
	mlx_put_image_to_window(game.mlx, game.win, game.img8, 800, 800);
	
	mlx_hook(game.win, CLOSE, 0, ft_close_red_cross, &game);
	
	//mlx_key_hook(game.win, key_hook, &game); // Cuando se produce evento pulsación tecla en ventana vars.win 
	mlx_loop(game.mlx);

	return (0);
}
