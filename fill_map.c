/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:09:24 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/21 14:19:57 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_map *map, t_game *game)
{
	put_player(map, game, 'd');
	put_exit_and_enemy(map, game);
	put_wall_and_ground(map, game);
	put_coin(map, game);
}
