/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:23:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 10:07:47 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	map.file = argv[1];
	valid_map_call(argc, map.file, &map);
	get_map_size(&map);
	valid_map_size(&map);
	allocation(&map);
	valid_map_draw(&map);
	return (0);
}

void	allocation(t_map *map)
{
	size_t	i;
	size_t	j;

	map->map = malloc(map->y * sizeof(char *));
	if (map->map == NULL)
		error_check(7, "ERROR!\nFail to allocate memory!");
	i = -1;
	while (++i < map->y)
	{
		map->map[i] = malloc((map->x + 1) * sizeof(char));
		if (map->map[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free(map->map[i]);
			error_check(7, "ERROR!\nFail to allocate memory!");
		}
	}
}
