/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:02:10 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/14 14:00:22 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

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
	
	/* game = NULL; */
	/* game.map.height = 10 * 110;
	game.map.width = 10 * 110; */
	if(argc == 0)
		return (0);
	ft_read_map(argv[1], &game);
	/* ft_read_map2(argv[1], &game);
	ft_cpy_map2(&game); */
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 128, game.map.height * 128, "----SO LONG----");
	/* ft_create_images2(&game);
	ft_put_images2(&game); */
	
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.door, 0, 0); */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.floor, 512, 0); */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.player_down, 256, 256); */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.player_left, 512, 512); */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.player_right, 720, 720); // ****'P' == player_right**** */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.player_up, 512, 0); */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.wall, 850, 850); */
	/* mlx_put_image_to_window(game->mlx, game->win, game->map.weapon, 800, 800); */
	
	mlx_hook(game.win, CLOSE, 0, ft_close_red_cross, &game);
	//mlx_key_hook(game.win, key_hook, &game); // Cuando se produce evento pulsación tecla en ventana vars.win 
	mlx_loop(game.mlx);
	return (0);
}
