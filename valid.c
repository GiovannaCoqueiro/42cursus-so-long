/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:15 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 20:00:58 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map_call(int argc, char *map_path, t_map *map)
{
	int	len;
	int	fd;

	if (argc < 2 || argc > 2)
		error_check(1, "ERROR!\nUsage: ./so_long maps/<file>.ber\n");
	len = ft_strlen(map_path);
	if (len <= 4 || (ft_strncmp(&map_path[len - 4], ".ber", 4) != 0))
		error_check(2, "ERROR!\nInvalid map name!\n");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error_check(3, "ERROR!\nMap does not exist!\n");
	}
	map->fd = fd;
}

void	valid_map_draw(t_map *map)
{
	t_map	copy;

	map->fd = open(map->file, O_RDONLY);
	draw_map(map);
	close(map->fd);
	if (check_for_wall_surround(map) == 0 || check_for_player_and_exit(map) == 0
		|| check_for_coins(map) == 0 || check_for_dif_char(map) == 0)
	{
		free_for_finish(map);
		error_check(8, "ERROR!\nMap does not match the requirements!\n");
	}
	copy.y = map->y;
	copy.x = map->x;
	allocation(&copy);
	copy_map(&copy, map);
	copy.path_check = 0;
	if (check_for_nopath(&copy, map->player_y, map->player_x) == 0)
	{
		free_for_finish(map);
		error_check(8, "ERROR!\nMap does not match the requirements!\n");
	}
	free_for_finish(&copy);
}
