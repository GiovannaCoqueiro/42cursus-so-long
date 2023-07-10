/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:23:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/26 17:07:01 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_sprite	spt;

	game.map = &map;
	game.spt = &spt;
	map.file = argv[1];
	game.steps = 0;
	valid_map_call(argc, map.file, &map);
	get_map_size(&map);
	allocation(&map);
	valid_map_draw(&map);
	game_init(&game);
	take_sprites(&game, &spt);
	fill_map(&map, &game);
	gameplay(&game);
}
