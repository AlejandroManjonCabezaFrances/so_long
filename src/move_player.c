/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:46:49 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:41 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void    ft_player_up(t_game *game, int h, int w)
{
	if (game->map.create_maps[h - 1][w] == 'S' 
		&& game->map.fire_count == game->map.fire_total)
	{
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		printf("WINNER!! You have every collectibles. \n");
		exit(0);
	}
	if (game->map.create_maps[h - 1][w] != '1' && game->map.create_maps[h - 1][w] != 'E')
	{
		if (game->map.create_maps[h - 1][w] == 'C')
			game->map.fire_count++;
		if (game->map.fire_count == game->map.fire_total)
			ft_open_exit(game);
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
			|| game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
			game->map.create_maps[h - 1][w] = 'U';
		game->map.create_maps[h][w] = '0';
		ft_print_map(game);
	}
}

void    ft_player_down(t_game *game, int h, int w)
{
	if (game->map.create_maps[h + 1][w] == 'S' 
		&& game->map.fire_count == game->map.fire_total)
	{
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		printf("WINNER!! You have every collectibles. \n");
		exit(0);
	}
	if (game->map.create_maps[h + 1][w] != '1' && game->map.create_maps[h + 1][w] != 'E' )
	{
		if (game->map.create_maps[h + 1][w] == 'C')
			game->map.fire_count++;
		if (game->map.fire_count == game->map.fire_total)
			ft_open_exit(game);
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
			|| game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
			game->map.create_maps[h + 1][w] = 'D';
		game->map.create_maps[h][w] = '0';
		ft_print_map(game);
	}
}

void    ft_player_left(t_game *game, int h, int w)
{
	if (game->map.create_maps[h][w - 1] == 'S' 
		&& game->map.fire_count == game->map.fire_total)
	{
		game->player.steps++;
		ft_printf("Steps-> %d\n", game->player.steps);
		printf("WINNER!! You have every collectibles. \n");
		exit(0);
	}
	if (game->map.create_maps[h][w - 1] != '1' && game->map.create_maps[h][w - 1] != 'E')
	{
		if (game->map.create_maps[h][w - 1] == 'C')
			game->map.fire_count++;
		if (game->map.fire_count == game->map.fire_total)
			ft_open_exit(game);
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
			|| game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
			game->map.create_maps[h][w - 1] = 'L';
		game->map.create_maps[h][w] = '0';
		ft_print_map(game);
	}
}

void    ft_player_rigth(t_game *game, int h, int w)
{
	if (game->map.create_maps[h][w + 1] == 'S' 
		&& game->map.fire_count == game->map.fire_total)
	{
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		printf("WINNER!! You have every collectibles. \n");
		exit(0);
	}
	if (game->map.create_maps[h][w + 1] != '1' && game->map.create_maps[h][w + 1] != 'E')
	{
		if (game->map.create_maps[h][w + 1] == 'C')
			game->map.fire_count++;
		if (game->map.fire_count == game->map.fire_total)
			ft_open_exit(game);
		game->player.steps++;
		printf("Steps-> %d\n", game->player.steps);
		if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
			|| game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
			game->map.create_maps[h][w + 1] = 'P';
		game->map.create_maps[h][w] = '0';
		ft_print_map(game);
	}
}
