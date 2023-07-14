/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:59:30 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/14 15:10:13 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	ft_read_map2(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		write(2, "Error\n", 6);
	line = get_next_line(fd);
	if (!line)
		write(2, "Error\n", 6);
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	printf("width-->%d***********\n", game->map.width);
	game->map.str_line = ft_strdup_no_new_line(line);
	free(line);
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		printf("---line despues del free--> %s----\n", line);
		
		if (line)
			game->map.str_line = ft_strjoin_no_new_line(game->map.str_line, line);
		printf("height-->%d***********\n", game->map.height);
		free(line);
	}
	printf("%s\n", game->map.str_line);
	close (fd);
}

int	ft_cpy_map2(t_game *game)
{
	int	i;
	int	h;
	int	w;

	i = 0;
	h = 0;
	
	game->map.create_maps = malloc(sizeof(char *) * (game->map.height) - 1);
	if (game->map.create_maps == NULL)
		return (0);
	while (h < game->map.height)
	{
		w = 0;
		game->map.create_maps[h] = malloc(sizeof(char) * game->map.width);
		if (game->map.create_maps[h] == NULL)
			return (0);
		while (w < game->map.width)
			game->map.create_maps[h][w++] = game->map.str_line[i++];
		game->map.create_maps[h][w] = '\0';
		h++;
	}
	game->map.create_maps[h] = 0;
	return (0);
}

void	ft_create_images2(t_game *game)
{
	int height;
	int width;
	
	game->map.door = mlx_xpm_file_to_image(game->mlx, "./xpm/door.xpm", &height, &width);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, "./xpm/floor2.xpm", &height, &width);
	game->map.player_down = mlx_xpm_file_to_image(game->mlx, "./xpm/player_down.xpm", &height, &width);
	game->map.player_left = mlx_xpm_file_to_image(game->mlx, "./xpm/player_left.xpm", &height, &width);
	game->map.player_right = mlx_xpm_file_to_image(game->mlx, "./xpm/player_right.xpm", &height, &width);
	game->map.player_up = mlx_xpm_file_to_image(game->mlx, "./xpm/player_up.xpm", &height, &width);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./xpm/wall.xpm", &height, &width);
	game->map.weapon = mlx_xpm_file_to_image(game->mlx, "./xpm/weapon.xpm", &height, &width);
}

void	ft_put_images2(t_game *game)
{
	int hei;
	int wid;

	hei = 0;
	while (hei < game->map.height)
	{
	 wid = 0;
		while  (wid < game->map.width)
		{
			if (game->map.create_maps[hei][wid] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, hei * 128, wid * 128);	
			else if (game->map.create_maps[hei][wid] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->map.weapon, hei * 128, wid * 128);
			else if (game->map.create_maps[hei][wid] == 'P')	
				mlx_put_image_to_window(game->mlx, game->win, game->map.player_right, hei * 128, wid * 128);
			else if (game->map.create_maps[hei][wid] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->map.door, hei * 128, wid * 128);		
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.floor, hei * 128, wid * 128);
		 	wid++;
		}
		hei++;
	}
}