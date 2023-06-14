/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:52:19 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 10:52:53 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (i == map->y - 1)
			map->map[i] = malloc((map->x + 1) * sizeof(char));
		else
			map->map[i] = malloc((map->x + 2) * sizeof(char));
		if (map->map[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free(map->map[i]);
			error_check(7, "ERROR!\nFail to allocate memory!");
		}
	}
}

void	free_for_finish(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->y)
		free(map->map[i]);
	free(map->map);
}
