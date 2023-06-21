/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 07:34:33 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/21 16:49:05 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gameplay(t_game *game)
{
	mlx_set_font(game->mlx, game->window, "6x10");
	mlx_key_hook(game->window, key_pressed, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, x_press, game);
	mlx_loop(game->mlx);
}

int	x_press(t_game *game)
{
	free_for_finish(game->map, game);
	return (1);
}

int	key_pressed(int key, t_game *game)
{
	if (key == XK_Escape)
		free_for_finish(game->map, game);
	else if (key == XK_d || key == XK_Right)
		step_right(game->map, game);
	else if (key == XK_a || key == XK_Left)
		step_left(game->map, game);
	else if (key == XK_w || key == XK_Up)
		step_up(game->map, game);
	else if (key == XK_s || key == XK_Down)
		step_down(game->map, game);
	print_steps(game);
	return (1);
}
