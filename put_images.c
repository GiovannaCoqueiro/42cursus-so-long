/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:47:33 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 18:49:22 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_map *map, t_game *game)
{
	put_player(map, game);
	put_exit_and_enemy(map, game);
	put_wall_and_ground(map, game);
	put_coin(map, game);
}

void	put_player(t_map *map, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->finn_d,
		map->player_x * 64, map->player_y * 64);
}

void	put_exit_and_enemy(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit,
					x * 64, y * 64);
			else if (map->map[y][x] == 'X')
				mlx_put_image_to_window(game->mlx, game->window, game->iceking,
					x * 64, y * 64);
		}
	}
}

void	put_wall_and_ground(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall,
					x * 64, y * 64);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->ground,
					x * 64, y * 64);
		}
	}
}

void	put_coin(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->coin,
					x * 64, y * 64);
	}
}
