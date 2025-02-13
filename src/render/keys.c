/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:09:11 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/08 14:09:35 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int  limits_checker(t_map *origin, int x, int y)
{
    t_map	*map;
	
	map = origin;
	while (map)
	{
		if (map->line == y)
			break ;
		map = map->nxt;
	}
	if (!map)
		return (0);
	while (map)
	{
		if (map->line == x)
			break ;
		map = map->down;		
	}	
	if (map->content == '1')
		return (0);
    return (1);
}

static int	control_map_limits(t_game *gm, int x, int y)
{
	//t_map	*map;
	int		new_y;
	int		new_x;
	
	//map = gm->map_position;
	new_x = (x + (gm->tile.base/2)) / gm->tile.base;
	new_y = (y + (gm->tile.base/2)) / gm->tile.base;
	x /= gm->tile.base;
	y /= gm->tile.base;
	if (limits_checker(gm->map_position, x, y) == 0)
		return (0);
    if (limits_checker(gm->map_position, new_x, y) == 0)
        return (0);
    if (limits_checker(gm->map_position, x, new_y) == 0)
        return (0);
    if (limits_checker(gm->map_position, new_x, new_y) == 0)
        return (0);
    return (1);
}

// static int	control_map_limits(t_game *gm, int x, int y)
// {
// 	t_map	*map;
	
// 	map = gm->map;
// 	x /= gm->tile.base;
// 	y /= gm->tile.base;
// 	while (map)
// 	{
// 		printf("map->line: %d map->column: %d\n", map->line, map->column);
// 		if (map->line == x && map->column == y)
// 			break ;
// 		map = map->nxt;
// 	}
// 	printf("%c\n", map->content);
// 	if (map->content == '1')
// 		return (0);
// 	return (1);
// }

void    ft_reles(mlx_key_data_t keydata, t_game *gm)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		gm->cam->l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		gm->cam->l_r = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		gm->cam->rotation = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		gm->cam->rotation = 0;
}

void    mlx_key(mlx_key_data_t keydata, void *ml)
{
	t_game *gm;

	gm = (t_game *)ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
    {
        mlx_close_window(gm->mlx_on);
		clean_exit(gm, 0);
        return ;
    }
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
	{
		if (control_map_limits(gm, gm->cam->plr_x - 5, gm->cam->plr_y) == 0)
			gm->cam->l_r = -5;
	}
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS)) // move right
	{
		if (control_map_limits(gm, gm->cam->plr_x - 5, gm->cam->plr_y) == 0)
			gm->cam->l_r = 5;
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS)) // move down
	{
		if (control_map_limits(gm, gm->cam->plr_x - 5, gm->cam->plr_y) == 0)
			gm->cam->l_r = -5;
	}
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS)) // move down
	{
		if (control_map_limits(gm, gm->cam->plr_x - 5, gm->cam->plr_y) == 0)
			gm->cam->l_r = -5;
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) // rotate left
		gm->cam->rotation = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) // rotate right
		gm->cam->rotation = 1;
	ft_reles(keydata, gm);
}