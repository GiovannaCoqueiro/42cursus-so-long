/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:32:08 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 19:33:35 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_sprites(t_game *game)
{
	game->finn_d = mlx_xpm_file_to_image(game->mlx, FINN_D, &game->img_width,
			&game->img_height);
	game->finn_l = mlx_xpm_file_to_image(game->mlx, FINN_L, &game->img_width,
			&game->img_height);
	game->finn_r = mlx_xpm_file_to_image(game->mlx, FINN_R, &game->img_width,
			&game->img_height);
	game->finn_u = mlx_xpm_file_to_image(game->mlx, FINN_U, &game->img_width,
			&game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->img_width,
			&game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &game->img_width,
			&game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width,
			&game->img_height);
	game->iceking = mlx_xpm_file_to_image(game->mlx, ICEKING, &game->img_width,
			&game->img_height);
	game->coin = mlx_xpm_file_to_image(game->mlx, COIN, &game->img_width,
			&game->img_height);
	if (game->finn_d == NULL || game->finn_l == NULL || game->finn_r == NULL
		|| game->finn_u == NULL || game->exit == NULL || game->ground == NULL
		|| game->wall == NULL || game->iceking == NULL || game->coin == NULL)
	{
		error_check(11, "ERROR!\nFail to take images!\n", 2, game);
	}
}
