/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:12:45 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/26 12:51:11 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

void	ft_error(char *word)
{
	write(2, word, ft_strlen(word));
	exit(1);
}

void	ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;	
	}
	free(str);
}

void	ft_open_exit(t_game *game)
{
	int h;
	int w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			if (game->map.create_maps[h][w] == 'E')
				game->map.create_maps[h][w] = 'S';
			w++;
		}
		h++;
	}
}
