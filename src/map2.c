/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:47:25 by amanjon-          #+#    #+#             */
/*   Updated: 2023/08/02 08:58:21 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_xpm(void *xpm_save)
{
	if (!xpm_save)
		ft_error("Error: .xpm");
}

void	ft_create_images(t_game *game)
{
	int	h;
	int	w;

	game->map.exit_on = mlx_xpm_file_to_image(game->mlx, EXITON, &w, &h);
	ft_check_xpm(game->map.exit_on);
	game->map.exit_off = mlx_xpm_file_to_image(game->mlx, EXITOFF, &w, &h);
	ft_check_xpm(game->map.exit_off);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &w, &h);
	ft_check_xpm(game->map.floor);
	game->player.player_down = mlx_xpm_file_to_image(game->mlx, DOWN, &w, &h);
	ft_check_xpm(game->player.player_down);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, LEFT, &w, &h);
	ft_check_xpm(game->player.player_left);
	game->player.player_right = mlx_xpm_file_to_image(game->mlx, RIGHT, &w, &h);
	ft_check_xpm(game->player.player_right);
	game->player.player_up = mlx_xpm_file_to_image(game->mlx, UP, &w, &h);
	ft_check_xpm(game->player.player_up);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, WALL, &w, &h);
	ft_check_xpm(game->map.wall);
	game->map.collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIB, &w, &h);
	ft_check_xpm(game->map.collectible);
}

void	ft_print_map3(t_game *game, int h, int w)
{
	if (game->map.create_maps[h][w] == 'D')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_down, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.exit_off, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == 'S')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.exit_on, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.floor, w * RESOLUTION_W, h * RESOLUTION_H);
}

void	ft_print_map2(t_game *game, int h, int w)
{
	if (game->map.create_maps[h][w] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.wall, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.collectible, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_right, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == 'L')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_left, w * RESOLUTION_W, h * RESOLUTION_H);
	else if (game->map.create_maps[h][w] == 'U')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_up, w * RESOLUTION_W, h * RESOLUTION_H);
	ft_print_map3(game, h, w);
}

void	ft_print_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			ft_print_map2(game, h, w);
			w++;
		}
		h++;
	}
}
