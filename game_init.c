/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:47:00 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 19:44:27 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error_check(9, "ERROR\nCouldn't connect with Xserver!\n", 1, game);
	game->window = mlx_new_window(game->mlx, (game->map->width * 64),
			(game->map->height * 64), "Adventure Time!");
	if (game->window == NULL)
	{
		free(game->mlx);
		error_check(10, "ERROR\nCouldn't open the window!\n", 1, game);
	}
}
