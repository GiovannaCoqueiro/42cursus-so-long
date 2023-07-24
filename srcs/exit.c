/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:50:21 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/07/24 07:53:25 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(int i, char *errormsg, int program_stage, t_game *game)
{
	if (program_stage >= 1)
	{
		free_map(game->map);
		if (program_stage == 2)
		{
			mlx_destroy_window(game->mlx, game->window);
			free_images(game);
			free_exit(game);
			free_win(game);
			free_death(game);
			free_mlx(game);
		}
	}
	ft_printf("%s", errormsg);
	exit(i);
}

void	free_for_finish(t_map *map, t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_images(game);
	free_exit(game);
	free_win(game);
	free_death(game);
	free_map(map);
	free_mlx(game);
	exit(0);
}
