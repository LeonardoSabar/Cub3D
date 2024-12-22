/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:01:44 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/21 19:01:44 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void init_player(t_player *player)
{
    player->direction = '\0';
    player->pos_x = 0.0;
    player->pos_y = 0.0;
    player->dir_x = 0.0;
    player->dir_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = 0.0;
    player->move_x = 0.0;
    player->move_y = 0.0;
    player->angle = 0.0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->windows = NULL;
	data->width = WIN_WIDTH;
	data->height = WIN_HEIGHT;
	init_player(&data->player);
	data->map = NULL;
	data->textures = NULL; // CONFIRMAR SE É ASSIM
}