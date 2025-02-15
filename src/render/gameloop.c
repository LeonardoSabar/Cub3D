/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:57:45 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/13 15:21:30 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    rotate_player(t_game *gm, int i)
{
	if (i == 1)
	{
		gm->cam->angle += ROT_SPEED;
		if (gm->cam->angle > 2 * M_PI)
			gm->cam->angle -= 2 * M_PI;
	}
	else
	{
		gm->cam->angle -= ROT_SPEED;
		if (gm->cam->angle < 0)
			gm->cam->angle += 2 * M_PI;
	}
}

void    move_player(t_game *gm, double move_x, double move_y)
{
	int     map_grid_y;
	int     map_grid_x;
	int     new_x;
	int     new_y;
    t_map   *map;

    map = gm->map_position;
	new_x = roundf(gm->cam->plr_x + move_x);
	new_y = roundf(gm->cam->plr_y + move_y);
	map_grid_x = (new_x / gm->tile.base);
	map_grid_y = (new_y / gm->tile.base);
	while (map)
    {
        if (map->column == map_grid_y && map->line == map_grid_x)
            break ;
        map = map->nxt;
    }
    if (map && map->content == '0')
	{
		gm->cam->plr_x = new_x;
		gm->cam->plr_y = new_y;
	}
}

void    hook(t_game *gm, double move_x, double move_y)
{
	if (gm->cam->rotation == 1)
		rotate_player(gm, 1);
	else if (gm->cam->rotation == -1)
		rotate_player(gm, -1);
	else if (gm->cam->l_r == 1)
	{
		move_x = -sin(gm->cam->angle);
		move_y = cos(gm->cam->angle);
	}
	else if (gm->cam->l_r == -1)
	{
		move_x = sin(gm->cam->angle);
		move_y = -cos(gm->cam->angle);
	}
	move_player(gm, move_x, move_y);
}

// void    game_loop(void *game)
// {
// 	t_game	*gm;

// 	gm = (t_game *)game;
// 	if (gm->game)
// 		mlx_delete_image(gm->mlx_on, gm->game);
// 	gm->game = mlx_new_image(gm->mlx_on, WIDTH, HEIGHT);
// 	hook(gm, 0, 0);
// //	cast_rays(gm);
// //	raycast(gm);
// 	mlx_image_to_window(gm->mlx_on, gm->game, 0, 0);
// }