/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:16:06 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/31 11:09:09 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	ft_floodfill(t_game *game, int h, int w)
{
	if (game->map.cpy_create_maps[h][w] == '1' 
		|| game->map.cpy_create_maps[h][w] == 'F'
		|| game->map.cpy_create_maps[h][w] == 'E')
		return ;
	game->map.cpy_create_maps[h][w] = 'F';
	ft_floodfill(game, h + 1, w);
	ft_floodfill(game, h - 1, w);
	ft_floodfill(game, h, w + 1);
	ft_floodfill(game, h, w - 1);
	return ;
}

void	ft_find_player(t_game *game)
{
	int h;
	int w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			if (game->map.create_maps[h][w] == 'P')
				break;
			w++;
		}
		if (game->map.create_maps[h][w] == 'P')
			break;
		h++;
	}
	ft_floodfill(game, h, w);
}

void   ft_cpy_map_for_floodfill(t_game *game)
{
	int h;
	int w;

	h = 0;
	game->map.cpy_create_maps = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.cpy_create_maps)
		return ;
	while (h < game->map.height)
	{
		w = 0;
		game->map.cpy_create_maps[h] = malloc(sizeof(char) * game->map.width);
		if (!game->map.cpy_create_maps[h])
			return ;
		while (w < game->map.width)
		{
			game->map.cpy_create_maps[h][w] = game->map.create_maps[h][w];
			w++;
		}
		game->map.cpy_create_maps[h][w] = '\0';
		h++;
	}
	game->map.cpy_create_maps[h] = 0;
}

int ft_check_path(t_game *game)
{
	int h;
	int w;
	
	ft_cpy_map_for_floodfill(game);
	ft_find_player(game);
	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{	
			if (game->map.cpy_create_maps[h][w] == 'P' 
				|| game->map.cpy_create_maps[h][w] == 'C' 
				|| (game->map.cpy_create_maps[h][w] == 'E'
				&& game->map.cpy_create_maps[h - 1][w] != 'F'
				&& game->map.cpy_create_maps[h + 1][w] != 'F'
				&& game->map.cpy_create_maps[h][w + 1] != 'F'
				&& game->map.cpy_create_maps[h][w - 1] != 'F'))
				ft_error("Error: Path invalid -floodfill-");
			w++;	
		}
		h++;
	}
	h = 0;
	return (1);
}
