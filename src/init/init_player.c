/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:54:52 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/16 06:04:24 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static t_vector define_vector(float x, float y)
{
	t_vector vector;
	vector.x = x;
	vector.y = y;
	return (vector);
}


static void define_direction(t_game *game)
{
	if (game->player.dir == 'N')
	{
		game->direction = define_vector(0, -1);
		game->plane = define_vector(0.66, 0);
	}
	else if (game->player.dir == 'S')
	{
		game->direction = define_vector(0, 1);
		game->plane = define_vector(-0.66, 0);
	}
	else if (game->player.dir == 'W')
	{
		game->direction = define_vector(-1, 0);
		game->plane = define_vector(0, -0.66);
	}
	else if (game->player.dir == 'E')
	{
		game->direction = define_vector(1, 0);
		game->plane = define_vector(0, 0.66);
	}
}



void init_player(t_game *game)
{
	game->position = define_vector(game->player.pos_x + 0.5, 
			game->player.pos_y + 0.5);
	define_direction(game);
}


/*
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
*/