/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:40:07 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 19:40:45 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_map *map)
{
	char	*line;
	int		count;

	map->width = 0;
	count = 0;
	while (1)
	{
		line = get_next_line(map->fd);
		if (line == NULL)
			break ;
		count++;
		if (map->width == 0)
			map->width = ft_strlen(line) - 1;
		if (map->width != ft_strlen(line) - 1 && line[map->width] != '\0')
		{
			free(line);
			error_check(6, "ERROR!\nThe map must be rectangular!\n", 0, NULL);
		}
		free(line);
	}
	map->height = count;
	if (map->height > 16 || map->width > 40)
		error_check(5, "ERROR!\nMap is too big!\n", 0, NULL);
	map->size = map->width * map->height;
	close(map->fd);
}

void	draw_map(t_map *map)
{
	int		x_count;
	int		y_count;
	char	*temp;

	temp = malloc(2 * sizeof(char));
	if (temp == NULL)
		return ;
	y_count = -1;
	while (++y_count < map->height)
	{
		x_count = -1;
		while (++x_count <= map->width)
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
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j <= map->width)
			copy->map[i][j] = map->map[i][j];
	}
}
