/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:17:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/14 10:08:02 by gcoqueir         ###   ########.fr       */
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
}			t_map;

void	valid_map_call(int argc, char *map_path, t_map *map);
void	get_map_size(t_map *map);
void	valid_map_size(t_map *map);
void	allocation(t_map *map);
void	valid_map_draw(t_map *map);
void	draw_map(t_map *map);
void	error_check(int i, char *errormsg);

#endif