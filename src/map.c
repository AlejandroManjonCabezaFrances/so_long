/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:19:41 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/26 15:38:38 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	ft_check_map_with_break_line_start(char *line)
{
	if (line[0] == '\n')
		ft_error("Error: about break line start\n");
}

void	ft_check_map_with_break_line_end(t_game *game)
{
	int i;
	size_t len;

	i = 0;
	len = ft_strlen(game->map.str_line);
	if (len > 0 && game->map.str_line[len - 1] == '\n')
		ft_error("Error: about break line end\n");
	while (game->map.str_line[i])
	{
		if (game->map.str_line[i] == '\n' && game->map.str_line[i + 1] == '\n')
			ft_error("Error: break line in the middle");
			
		i++;
	}
}

char	*ft_read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		ft_error("Error: open file descriptor\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error: line to gnl\n");
	ft_check_map_with_break_line_start(line);
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		if (line)
			game->map.str_line = ft_strjoin(game->map.str_line, line);
		free(line);
	}
	ft_check_map_with_break_line_end(game);
	close (fd);
	return (game->map.str_line);
}

void	ft_cpy_map(char *read_map, t_game *game)
{
	/* int h;
	int w; */
	
	game->map.create_maps = ft_split(read_map, '\n');
	/* --------check_walls/map-------- */
	if (ft_check_walls(game) != 1)
	{	
		ft_free(game->map.create_maps);
		free(game->map.str_line);
	}
	if (ft_check_map(game) != 1)
	{
		free(game->map.str_line);
	}
	/* --------check_walls/map-------- */
	/* h = 0;
	while (game->map.create_maps[h])
	{
		w = 0;
		while (game->map.create_maps[h][w])
		{
			printf("%c", game->map.create_maps[h][w]);
			w++;
		}
		printf("\n");
		h++;
	} */
}

void	ft_check_xpm(void *xpm_save)
{
	if (!xpm_save)
		ft_error("Error: .xpm");
}

void	ft_create_images(t_game *game)
{
	int h;
	int w;
	
	game->map.exit_on = mlx_xpm_file_to_image(game->mlx, "./xpm/exiton128.xpm", &w, &h);
		ft_check_xpm(game->map.exit_on);
	game->map.exit_off = mlx_xpm_file_to_image(game->mlx, "./xpm/exitoff128.xpm", &w, &h);
		ft_check_xpm(game->map.exit_off);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, "./xpm/floor128.xpm", &w, &h);
		ft_check_xpm(game->map.floor);
	game->player.player_down = mlx_xpm_file_to_image(game->mlx, "./xpm/player_down.xpm", &w, &h);
		ft_check_xpm(game->player.player_down);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, "./xpm/player_left.xpm", &w, &h);
		ft_check_xpm(game->player.player_left);
	game->player.player_right = mlx_xpm_file_to_image(game->mlx, "./xpm/player_right.xpm", &w, &h);
		ft_check_xpm(game->player.player_right);
	game->player.player_up = mlx_xpm_file_to_image(game->mlx, "./xpm/player_up.xpm", &w, &h);
		ft_check_xpm(game->player.player_up);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./xpm/wall128.xpm", &w, &h);
		ft_check_xpm(game->map.wall);
	game->map.collectible = mlx_xpm_file_to_image(game->mlx, "./xpm/collectible128.xpm", &w, &h);
		ft_check_xpm(game->map.collectible);
}

void	ft_print_map(t_game *game)
{
	int h;
	int w;

	h = 0;
	while (game->map.create_maps[h])
	{
		w = 0;
		while (game->map.create_maps[h][w])
		{
			printf("%c", game->map.create_maps[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	h = 0;
	while (h < game->map.height)
	{
	 w = 0;
		while  (w < game->map.width)
		{
			if (game->map.create_maps[h][w] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, w * RESOLUTION_W, h * RESOLUTION_H);	
			else if (game->map.create_maps[h][w] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->map.collectible, w * RESOLUTION_W, h * RESOLUTION_H);
			else if (game->map.create_maps[h][w] == 'P')	
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_right, w * RESOLUTION_W, h * RESOLUTION_H);
			else if (game->map.create_maps[h][w] == 'L')	
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_left, w * RESOLUTION_W, h * RESOLUTION_H);
			else if (game->map.create_maps[h][w] == 'U')	
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_up, w * RESOLUTION_W, h * RESOLUTION_H);
			else if (game->map.create_maps[h][w] == 'D')	
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_down, w * RESOLUTION_W, h * RESOLUTION_H);
			else if (game->map.create_maps[h][w] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->map.exit_off, w * RESOLUTION_W, h * RESOLUTION_H);
			else if (game->map.create_maps[h][w] == 'S')
				mlx_put_image_to_window(game->mlx, game->win, game->map.exit_on, w * RESOLUTION_W, h * RESOLUTION_H);		
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.floor, w * RESOLUTION_W, h * RESOLUTION_H);
		 	w++;
		}
		h++;
	}
}

void	ft_count_total_collectibles(t_game *game)
{
	int h;
	int w;
	int count;

	h = 0;
	count = 0;
	while (game->map.create_maps[h])
	{
		w = 0;
		while (game->map.create_maps[h][w])
		{
			if (game->map.create_maps[h][w] == 'C')
				count++;
				game->map.fire_total = count;
			w++;
		}
		h++;
	}
}
