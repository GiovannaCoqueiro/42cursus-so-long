/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:40:07 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 14:12:52 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_map *map)
{
	char	*line;
	size_t	count;

	map->x = 0;
	count = 0;
	while (1)
	{
		line = get_next_line(map->fd);
		if (line == NULL)
			break ;
		count++;
		if (map->x == 0)
			map->x = ft_strlen(line) - 1;
		if (map->x != ft_strlen(line) - 1 && line[map->x] != '\0')
		{
			free(line);
			error_check(6, "ERROR!\nThe map must be rectangular!\n");
		}
		free(line);
	}
	map->y = count;
	if (map->y > 16 || map->x > 40)
		error_check(5, "ERROR!\nMap is too big!\n");
	map->size = map->x * map->y;
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

void	copy_map(t_map *copy, t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j <= map->x)
			copy->map[i][j] = map->map[i][j];
	}
}
