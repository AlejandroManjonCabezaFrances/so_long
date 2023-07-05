/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:02:10 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/05 16:08:08 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

/* typedef struct s_game 
{
	void	*mlx;
	void	*win;	
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

	if(argc == 0 || *argv == 0)
		return (0);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1080, 1080, "----SO_LONG----");
	game.map.height = 500;
	game.map.weidth = 500;
	game.img = mlx_xpm_file_to_image(game.mlx, "./xpm/death_0.xpm", &game.map.height, &game.map.weidth);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_hook(game.win, CLOSE, 0, ft_close_red_cross, &game);
	//mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	/* mlx_key_hook(game.win, key_hook, &game); */ // Cuando se produce evento pulsación tecla en ventana vars.win 
	mlx_loop(game.mlx);

	return (0);
}
