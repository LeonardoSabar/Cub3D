/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:54:52 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/13 13:05:38 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	start_cam_infor(t_game *game)
{
	game->cam->plr_x = game->player.pos_x * game->tile.base + game->tile.base / 2;
	game->cam->plr_y = game->player.pos_y * game->tile.base + game->tile.base / 2;
	game->cam->fov_plr = (FOV * M_PI) / 180;
	if (game->player.dir == 'N')
		game->cam->angle = M_PI * NORTH;
	else if (game->player.dir == 'S')
		game->cam->angle = M_PI * SOUTH;
	else if (game->player.dir == 'W')
		game->cam->angle = M_PI * WEST;
	printf("plr_x: %f plr_y: %f dir: %c angle: %f\n", game->player.pos_x, game->player.pos_y, game->player.dir, game->cam->angle);
}