/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:58:16 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/10 18:12:27 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    game_loop2(void *game)
{
	t_game	*gm;

	gm = (t_game *)game;
	if (gm->game)
		mlx_delete_image(gm->mlx_on, gm->game);
	gm->game = mlx_new_image(gm->mlx_on, WIDTH, HEIGHT);
//	hook(gm, 0, 0);
//	cast_rays(gm);
//	raycast(gm);
	mlx_image_to_window(gm->mlx_on, gm->game, 0, 0);
}