/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_draw_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:05:13 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 19:13:36 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_wall_surround(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->x)
		if (map->map[0][i] != '1' || map->map[map->y - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < map->y)
		if (map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
			return (0);
	return (1);
}

int	check_for_player_and_exit(t_map *map)
{
	size_t	i;
	size_t	j;

	map->player = 0;
	map->exit = 0;
	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			if (map->map[i][j] == 'P')
			{
				map->player++;
				map->player_x = j;
				map->player_y = i;
			}
			if (map->map[i][j] == 'E')
				map->exit++;
		}
	}
	if (map->player != 1 || map->exit != 1)
		return (0);
	return (1);
}

int	check_for_coins(t_map *map)
{
	size_t	i;
	size_t	j;

	map->coin = 0;
	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
			if (map->map[i][j] == 'C')
				map->coin++;
	}
	if (map->coin < 1)
		return (0);
	return (1);
}

int	check_for_dif_char(t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
			if (ft_strchr(MAP_CHARS, map->map[i][j]) == NULL)
				return (0);
	}
	return (1);
}

// int	check_for_nopath(t_map *map, size_t y, size_t x)
// {
// 	if ((y - 1) > map->y || (y + 1) >= map->y || (x - 1) < map->x ||
// 		(x + 1) >= map->x)
// 		return (0);
// 	map->map[y][x] = '1';
// 	if (map->map[y - 1][x] != 'E' && map->map[y + 1][x] != 'E' &&
// 		map->map[y][x - 1] != 'E' && map->map[y][x + 1] != 'E')
// 	{
// 		if (ft_strchr("1X", map->map[y - 1][x]) == NULL)
// 			check_for_nopath(map, y - 1, x);
// 		if (ft_strchr("1X", map->map[y + 1][x]) == NULL)
// 			check_for_nopath(map, y + 1, x);
// 		if (ft_strchr("1X", map->map[y][x - 1]) == NULL)
// 			check_for_nopath(map, y, x - 1);
// 		if (ft_strchr("1X", map->map[y][x + 1]) == NULL)
// 			check_for_nopath(map, y, x + 1);
// 	}
// 	else
// 		map->path_check = 1;
// 	if (map->path_check == 1)
// 		return (1);
// 	return (0);
// }
