/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:12:45 by amanjon-          #+#    #+#             */
/*   Updated: 2023/08/04 09:40:37 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *word)
{
	write(2, word, ft_strlen(word));
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

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
	int	h;
	int	w;

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

void	ft_count_total_collectibles(t_game *game)
{
	int	h;
	int	w;
	int	count;

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

char	*ft_strjoin_so_long(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[j] = s2[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}
