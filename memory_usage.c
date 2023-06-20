/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:52:19 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 14:12:07 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocation(t_map *map)
{
	int	i;
	int	j;

	map->map = malloc(map->height * sizeof(char *));
	if (map->map == NULL)
		error_check(7, "ERROR!\nFail to allocate memory!");
	i = -1;
	while (++i < map->height)
	{
		if (i == map->height - 1)
			map->map[i] = malloc((map->width + 1) * sizeof(char));
		else
			map->map[i] = malloc((map->width + 2) * sizeof(char));
		if (map->map[i] == NULL)
		{
			j = -1;
			while (++j < i)
				free(map->map[i]);
			error_check(7, "ERROR!\nFail to allocate memory!");
		}
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->map[i]);
	free(map->map);
}
