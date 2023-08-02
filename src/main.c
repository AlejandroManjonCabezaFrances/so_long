/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:02:10 by amanjon-          #+#    #+#             */
/*   Updated: 2023/08/02 11:35:25 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close_red_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	ft_loop_hook(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx, game->win, 30, 10, 0x000000, str);
	free(str);
	return (0);
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*read_map;

	game.map.fire_count = 0;
	ft_check_input(argc, argv);
	read_map = ft_read_map(argv[1], &game);
	ft_cpy_map(read_map, &game);
	ft_check_path(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 128,
			game.map.height * 128, "Oo---So ShoRt---oO");
	if (!game.win)
	{
		free(game.mlx);
		return (1);
	}
	ft_create_images(&game);
	ft_print_map(&game);
	ft_count_total_collectibles(&game);
	atexit(leaks);
	mlx_hook(game.win, KEY_PRESS, 0, &ft_key_press, &game);
	mlx_loop_hook(game.mlx, &ft_loop_hook, &game);
	mlx_hook(game.win, CLOSE_RED, 0, &ft_close_red_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}
