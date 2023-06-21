/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:23:47 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/21 08:42:27 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	game.steps = 0;
	gameplay(&game);




	return (0);
}
