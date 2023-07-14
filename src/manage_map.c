/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:19:41 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/14 15:10:09 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	ft_read_map(char *filename, t_game *game)
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
	game->map.str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->map.height++;
		line = get_next_line(fd);
		printf("---line despues del free--> %s----\n", line);
		
		if (line)
			game->map.str_line = ft_strjoin(game->map.str_line, line);
		printf("height-->%d***********\n", game->map.height);
		free(line);
	}
	printf("%s\n", game->map.str_line);
	close (fd);
}