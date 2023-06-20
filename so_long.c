/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:23:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 19:14:37 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_game *test)
{
	if (key == XK_Escape)
		mlx_destroy_window(test->mlx, test->window);
	return (1);
}

int	no_input(void)
{
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	game.map = &map;
	map.file = argv[1];
	valid_map_call(argc, map.file, &map);
	get_map_size(&map);
	allocation(&map);
	valid_map_draw(&map);


	game_init(&game);
	take_sprites(&game);
	fill_map(&map, &game);


	mlx_loop_hook(game.mlx, no_input, &game);
	mlx_key_hook(game.window, key_pressed, &game);
	mlx_loop(game.mlx);
	free_images(&game);
	free_mlx(&game);

	free_map(&map);
	return (0);
}
