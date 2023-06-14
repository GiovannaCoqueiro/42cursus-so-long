/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:17:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 19:14:44 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAP_CHARS "01CEPX"

typedef struct s_map
{
	char	*file;
	int		fd;
	char	**map;
	int		size;
	size_t	y;
	size_t	x;
	int		player;
	int		exit;
	int		coin;
	size_t	player_x;
	size_t	player_y;
	int		path_check;
}			t_map;

void		valid_map_call(int argc, char *map_path, t_map *map);
void		get_map_size(t_map *map);
void		allocation(t_map *map);
void		valid_map_draw(t_map *map);
void		draw_map(t_map *map);
int			check_for_wall_surround(t_map *map);
int			check_for_player_and_exit(t_map *map);
int			check_for_coins(t_map *map);
int			check_for_dif_char(t_map *map);
// int			check_for_nopath(t_map *map, size_t y, size_t x);
void		copy_map(t_map *copy, t_map *map);
void		free_for_finish(t_map *map);
void		error_check(int i, char *errormsg);

#endif