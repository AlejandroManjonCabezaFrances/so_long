/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:19:41 by amanjon-          #+#    #+#             */
/*   Updated: 2023/08/01 09:24:09 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_map_with_break_line_start(char *line)
{
	if (line[0] == '\n')
		ft_error("Error: about break line start\n");
}

void	ft_check_map_with_break_line_end_middle(t_game *game)
{
	int		i;
	size_t	len;

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
	ft_check_map_with_break_line_end_middle(game);
	close (fd);
	return (game->map.str_line);
}

void	ft_cpy_map(char *read_map, t_game *game)
{	
	game->map.create_maps = ft_split(read_map, '\n');
	if (ft_check_walls(game) != 1)
	{	
		ft_free(game->map.create_maps);
		free(game->map.str_line);
	}
	if (ft_check_map(game) != 1)
	{
		free(game->map.str_line);
	}
}
