/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanjon- <amanjon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:13:00 by amanjon-          #+#    #+#             */
/*   Updated: 2023/07/25 15:24:40 by amanjon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

int ft_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (keycode == KEY_W || keycode == ARROW_UP)
		ft_key_w(game);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		ft_key_s(game);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		ft_key_a(game);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		ft_key_d(game);
	return (1);
}

void    ft_key_w(t_game *game)
{
    int h;
    int w;

    h = 0;
    while (h < game->map.height)
    {
        w = 0;
        while (w < game->map.width)
        {
            if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
                || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
                break;
            w++;
        }
        if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
            || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
            break;
        h++;
    }
    ft_player_up(game, h, w);
}

void    ft_key_s(t_game *game)
{
    int h;
    int w;

    h = 0;
    while (h < game->map.height)
    {
        w = 0;
        while (w < game->map.width)
        {
            if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
                || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
                break;
            w++;
        }
        if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
            || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
            break;
        h++;
    }
    ft_player_down(game, h, w);
}

void    ft_key_a(t_game *game)
{
    int h;
    int w;

    h = 0;
    while (h < game->map.height)
    {
        w = 0;
        while (w < game->map.width)
        {
            if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
                || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
                break;
            w++;
        }
        if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
            || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
            break;
        h++;
    }
    ft_player_left(game, h, w);
}

void    ft_key_d(t_game *game)
{
    int h;
    int w;

    h = 0;
    while (h < game->map.height)
    {
        w = 0;
        while (w < game->map.width)
        {
            if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
                || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
                break;
            w++;
        }
        if (game->map.create_maps[h][w] == 'P' || game->map.create_maps[h][w] == 'L' 
            || game->map.create_maps[h][w] == 'U' || game->map.create_maps[h][w] == 'D')
            break;
        h++;
    }
    ft_player_rigth(game, h, w);
}