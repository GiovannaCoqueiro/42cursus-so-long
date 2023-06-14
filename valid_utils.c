/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:40:07 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 09:22:10 by gcoqueir         ###   ########.fr       */
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
	map->size = map->x * map->y;
	close(map->fd);
}

