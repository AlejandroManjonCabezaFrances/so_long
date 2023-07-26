/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:02:10 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/26 14:42:53 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int	ft_close_red_cross (t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

static	int	ft_loop_hook(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx, game->win, 30, 10, 0x000000, str);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char *read_map;
	
	game.map.fire_count = 0;
	/* if(argc == 0)
		return (0); */
	ft_check_input(argc, argv);
	read_map = ft_read_map(argv[1], &game);
	ft_cpy_map(read_map, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 128, game.map.height * 128, "0o---So ShoRt---o0");
	ft_create_images(&game);
	ft_print_map(&game);
	ft_count_total_collectibles(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &ft_key_press, &game);
	mlx_loop_hook(game.mlx, &ft_loop_hook, &game);
	mlx_hook(game.win, CLOSE_RED, 0, &ft_close_red_cross, &game);
	
	printf("\n\n\n");
	printf("valor de height-->%d\n", game.map.height);
	printf("valor de width-->%d\n", game.map.width);
	mlx_loop(game.mlx);
	return (0);
}

/* Errores no hechos;
1  si me pones una 'J' en el mapa "missing some ingredients" */
