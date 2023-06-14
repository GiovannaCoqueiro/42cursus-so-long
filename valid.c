/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:12:15 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 10:48:03 by gcoqueir         ###   ########.fr       */
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

void	valid_map_size(t_map *map)
{
	if (map->y > 16 || map->x > 40)
		error_check(5, "ERROR!\nMap is too big!\n");
}

void	valid_map_draw(t_map *map)
{
	map->fd = open(map->file, O_RDONLY);
	draw_map(map);
	close(map->fd);
}

void	draw_map(t_map *map)
{
	size_t	y_count;
	size_t	x_count;
	char	*temp;

	temp = malloc(2 * sizeof(char));
	if (temp == NULL)
		return ;
	y_count = -1;
	while (++y_count < map->y)
	{
		x_count = -1;
		while (++x_count <= map->x)
		{
			if (read(map->fd, temp, 1) == 0)
			{
				free(temp);
				map->map[y_count][x_count] = '\0';
				return ;
			}
			map->map[y_count][x_count] = *temp;
			temp[1] = '\0';
		}
		map->map[y_count][x_count] = '\0';
	}
	free(temp);
}
