/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:50:21 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/06/20 19:45:43 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(int i, char *errormsg, int program_stage, t_game *game)
{
	if (program_stage >= 1)
		free_map(game->map);
	if (program_stage == 2)
	{
		free_images(game);
		free_mlx(game);
	}
	ft_printf("%s", errormsg);
	exit(i);
}
