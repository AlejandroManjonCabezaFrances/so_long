/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:04:08 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/26 12:01:50 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int	ft_check_walls_2(t_game *game)
{
	int h;
	int current_width;
	int max_width;

	h = 0;
	max_width = 0;
	while (game->map.create_maps[h])
	{
		current_width = ft_strlen(game->map.create_maps[h]);
		if (current_width > max_width)
			max_width = current_width;
		h++;
	}
	h = 0;
	while (game->map.create_maps[h])
	{
		current_width = ft_strlen(game->map.create_maps[h]);
		if (current_width != max_width)
			ft_error("Error: lines with differents width");
		h++;
	}
	return (1);
}

int	ft_check_walls(t_game *game)
{
	int h;
	int w;

	h = 0;
	ft_check_walls_2(game);
	while (game->map.create_maps[h])
	{
		if (game->map.create_maps[h][0] != '1')
			ft_error("Error: walls left\n");
		if (game->map.create_maps[h][ft_strlen(game->map.create_maps[h]) - 1] != '1')
			ft_error("Error: walls right\n");
		h++;
	}
		h = 0;
		w = 0;
	while (game->map.create_maps[game->map.height - 1][w])
	{
		if (game->map.create_maps[0][w] != '1')
			ft_error("Error: walls up\n");
		if (game->map.create_maps[game->map.height - 1][w] != '1')
			ft_error("Error: walls down\n");
		w++;
	}
	return (1);
}

int	ft_missing_some_ingredients(char ingredient)
{
	if (ingredient != 'E' && ingredient != 'P' && ingredient != 'C' 
		&& ingredient != '1' && ingredient != '0')
		return (0);
	return (1);
}

int	ft_check_map(t_game *game)
{
	int i;
	int exit;
	int player;
	int collectible;

	i = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (game->map.str_line[i])
	{
		if (ft_missing_some_ingredients(*game->map.str_line) == 0)
			ft_error("Error: missing some ingredient in the map\n");
		if (game->map.str_line[i] == 'E')
			exit += 1;
		if (game->map.str_line[i] == 'P')
			player += 1;
		if (game->map.str_line[i] == 'C')
			collectible += 1;
    	i++;
	}
		if (exit != 1 ||player != 1 || collectible < 1)
			ft_error("Error: with the map 's ingredients\n");
		return (1);
	}

    int	ft_check_input(int argc, char **argv)
    {
    	if (argc != 2)
			ft_error("Error: numbers of arguments incorrect\n");
		if ((ft_strnstr((argv[1] + ft_strlen(argv[1]) - 4), ".ber", ft_strlen(argv[1]))) == 0)
			ft_error("Error: failed file .ber\n");
		return (1);
    }
	