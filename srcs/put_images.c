/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:47:33 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/26 11:13:54 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_map *map, t_game *game, t_sprite *spt, char direction)
{
	if (direction == 'r')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_r,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'l')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_l,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'u')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_u,
			map->player_x * 64, map->player_y * 64);
	else if (direction == 'd')
		mlx_put_image_to_window(game->mlx, game->window, spt->finn_d,
			map->player_x * 64, map->player_y * 64);
}

void	put_coin_and_enemy(t_map *map, t_game *game, t_sprite *spt)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, spt->coin,
					x * 64, y * 64);
			else if (map->map[y][x] == 'X')
				mlx_put_image_to_window(game->mlx, game->window, spt->iceking,
					x * 64, y * 64);
		}
	}
}

void	put_wall_and_ground(t_map *map, t_game *game, t_sprite *spt)
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
			{
				if (y == 0 && x == 0)
					mlx_put_image_to_window(game->mlx, game->window, spt->bmo,
						0, 0);
				else
					mlx_put_image_to_window(game->mlx, game->window, spt->wall,
						x * 64, y * 64);
			}
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, spt->ground,
					x * 64, y * 64);
		}
	}
}

void	put_exit(t_map *map, t_game *game, t_sprite *spt)
{
	int	y;
	int	x;
	int	delay;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'E')
			{
				delay = 0;
				while (delay++ < 4000)
					mlx_put_image_to_window(game->mlx, game->window, spt->exit1,
						x * 64, y * 64);
				while (delay++ < 8000)
					mlx_put_image_to_window(game->mlx, game->window, spt->exit2,
						x * 64, y * 64);
				while (delay++ < 12000)
					mlx_put_image_to_window(game->mlx, game->window, spt->exit3,
						x * 64, y * 64);
			}
		}
	}
}

void	print_steps(t_game *game)
{
	char	*steps;
	int		len;
	int		x;
	int		y;

	steps = ft_itoa(game->steps);
	len = ft_strlen(steps);
	x = 32 - (len * len);
	y = 30;
	mlx_string_put(game->mlx, game->window, x, y, 0x000000, steps);
	free(steps);
}
