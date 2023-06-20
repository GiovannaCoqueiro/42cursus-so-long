/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:17:10 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 18:01:32 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAP_CHARS "01CEPX"
# define FINN_D "./textures/finn_down_64.xpm"
# define FINN_L "textures/finn_left_64.xpm"
# define FINN_R "textures/finn_right_64.xpm"
# define FINN_U "textures/finn_up_64.xpm"
# define EXIT "textures/exit_64.xpm"
# define GROUND "textures/ground_64.xpm"
# define WALL "textures/wall_64.xpm"
# define ICEKING "textures/iceking_64.xpm"
# define COIN "textures/coin4_64.xpm"

typedef struct s_map
{
	char	*file;
	int		fd;
	char	**map;
	int		size;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		coin;
	int		player_x;
	int		player_y;
	int		path_check;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		img_width;
	int		img_height;
	void	*finn_d;
	void	*finn_l;
	void	*finn_r;
	void	*finn_u;
	void	*exit;
	void	*ground;
	void	*wall;
	void	*iceking;
	void	*coin;
	t_map	*map;
}			t_game;

void		valid_map_call(int argc, char *map_path, t_map *map);
void		get_map_size(t_map *map);
void		allocation(t_map *map);
void		valid_map_draw(t_map *map);
void		draw_map(t_map *map);
int			check_for_wall_surround(t_map *map);
int			check_for_player_and_exit(t_map *map);
int			check_for_coins(t_map *map);
int			check_for_dif_char(t_map *map);
void		copy_map(t_map *copy, t_map *map);
int			check_for_nopath(t_map *map, int y, int x);


void		game_init(t_game *game);
void		take_sprites(t_game *game);
void		fill_map(t_map *map, t_game *game);
void		put_player(t_map *map, t_game *game);
void		put_exit_and_enemy(t_map *map, t_game *game);
void		put_wall_and_ground(t_map *map, t_game *game);
void		put_coin(t_map *map, t_game *game);


void		free_map(t_map *map);
void		error_check(int i, char *errormsg);

#endif