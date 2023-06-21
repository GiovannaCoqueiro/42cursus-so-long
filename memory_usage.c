/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:52:19 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/21 07:53:11 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocation(t_map *map)
{
	int	i;
	int	j;

	map->map = malloc(map->height * sizeof(char *));
	if (map->map == NULL)
		error_check(7, "ERROR!\nFail to allocate memory!", 0, NULL);
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
			free(map->map);
			error_check(7, "ERROR!\nFail to allocate memory!", 0, NULL);
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

void	free_mlx(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_images(t_game *game)
{
	if (game->finn_d != NULL)
		mlx_destroy_image(game->mlx, game->finn_d);
	if (game->finn_l != NULL)
		mlx_destroy_image(game->mlx, game->finn_l);
	if (game->finn_r != NULL)
		mlx_destroy_image(game->mlx, game->finn_r);
	if (game->finn_u != NULL)
		mlx_destroy_image(game->mlx, game->finn_u);
	if (game->exit != NULL)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->ground != NULL)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->iceking != NULL)
		mlx_destroy_image(game->mlx, game->iceking);
	if (game->coin != NULL)
		mlx_destroy_image(game->mlx, game->coin);
}

void	free_for_finish(t_map *map, t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_images(game);
	free_map(map);
	free_mlx(game);
	exit(1);
}
