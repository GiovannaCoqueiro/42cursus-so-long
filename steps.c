/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:40:36 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/21 08:47:46 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_right(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1X", map->map[y][x + 1]) != NULL)
	{
		if (map->map[y][x + 1] == 'X')
			free_for_finish(map, game);
		return ;
	}
	if (map->map[y][x + 1] == 'E')
	{
		if (map->coin == 0)
			free_for_finish(map, game);
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y][x + 1] == 'C')
		map->coin--;
	map->map[y][x + 1] = 'P';
	map->player_x++;
	put_wall_and_ground(map, game);
	put_player(map, game);
	ft_printf("Steps: %d\n", ++game->steps);
}

void	step_left(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1X", map->map[y][x - 1]) != NULL)
	{
		if (map->map[y][x - 1] == 'X')
			free_for_finish(map, game);
		return ;
	}
	if (map->map[y][x - 1] == 'E')
	{
		if (map->coin == 0)
			free_for_finish(map, game);
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y][x - 1] == 'C')
		map->coin--;
	map->map[y][x - 1] = 'P';
	map->player_x--;
	put_wall_and_ground(map, game);
	put_player(map, game);
	ft_printf("Steps: %d\n", ++game->steps);
}

void	step_down(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1X", map->map[y + 1][x]) != NULL)
	{
		if (map->map[y + 1][x] == 'X')
			free_for_finish(map, game);
		return ;
	}
	if (map->map[y + 1][x] == 'E')
	{
		if (map->coin == 0)
			free_for_finish(map, game);
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y + 1][x] == 'C')
		map->coin--;
	map->map[y + 1][x] = 'P';
	map->player_y++;
	put_wall_and_ground(map, game);
	put_player(map, game);
	ft_printf("Steps: %d\n", ++game->steps);
}

void	step_up(t_map *map, t_game *game)
{
	int	y;
	int	x;

	y = map->player_y;
	x = map->player_x;
	if (ft_strchr("1X", map->map[y - 1][x]) != NULL)
	{
		if (map->map[y - 1][x] == 'X')
			free_for_finish(map, game);
		return ;
	}
	if (map->map[y - 1][x] == 'E')
	{
		if (map->coin == 0)
			free_for_finish(map, game);
		return ;
	}
	map->map[y][x] = '0';
	if (map->map[y - 1][x] == 'C')
		map->coin--;
	map->map[y - 1][x] = 'P';
	map->player_y--;
	put_wall_and_ground(map, game);
	put_player(map, game);
	ft_printf("Steps: %d\n", ++game->steps);
}
