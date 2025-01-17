/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:01:44 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/17 12:37:50 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#include <stdlib.h>
#include <string.h>
#include "cub3d.h" // Substitua pelo caminho correto do seu cabeçalho

void init_ray(t_ray *ray)
{
    ray->ray_ngl = 0.0;
    ray->distance = 0.0;
    ray->flag = 0;
}

void init_tile(t_tile *tile)
{
    tile->base = 0;
    tile->width = 0;
    tile->height = 0;
}

void init_img(t_img *img)
{
    img->texture = NULL;
    img->img = NULL;
}

void init_render_img(t_r_img *render_img)
{
    render_img->x = 0;
    render_img->y = 0;
    render_img->z = 0;
}

void init_obj(t_obj *obj)
{
    obj->onoff = 0;
    init_img(&obj->img);
    init_render_img(&obj->sizes);
}

void init_map(t_map *map)
{
    map->line = 0;
    map->column = 0;
    map->content = '\0';
    map->nxt = NULL;
    map->prv = NULL;
    map->up = NULL;
    map->down = NULL;
}

void init_cam(t_cam *cam)
{
    cam->plr_x = 0;
    cam->plr_y = 0;
    cam->rotation = 0;
    cam->l_r = 0;
    cam->angle = 0.0;
    cam->fov_plr = 0.0f;
}

void init_texinfo(t_texinfo *texinfo)
{
    texinfo->north = NULL;
    texinfo->south = NULL;
    texinfo->west = NULL;
    texinfo->east = NULL;
    texinfo->floor = NULL;
    texinfo->ceiling = NULL;
    texinfo->size = 0;
    texinfo->index = 0;
    texinfo->step = 0.0;
    texinfo->pos = 0.0;
    texinfo->x = 0;
    texinfo->y = 0;
}

void init_mapinfo(t_mapinfo *mapinfo)
{
    mapinfo->fd = -1;
    mapinfo->line_count = 0;
    mapinfo->path = NULL;
    mapinfo->file = NULL;
    mapinfo->height = 0;
    mapinfo->width = 0;
    mapinfo->index_end_of_map = 0;
}

void init_player(t_player *player)
{
    player->dir = 'N';
    player->pos_x = 0.0;
    player->pos_y = 0.0;
    player->dir_x = 1.0;
    player->dir_y = 0.0; 
    player->plane_x = 0.0;
    player->plane_y = 0.0;
    player->has_moved = 0;
    player->move_x = 0;
    player->move_y = 0;
    player->rotate = 0;
}

// Função para inicializar t_game
void init_data(t_game *data)
{
    data->is_horizon = 0;
    data->parse_map = NULL;
    data->map = NULL;
    init_player(&data->player);
    init_texinfo(&data->texinfo);
    init_mapinfo(&data->mapinfo);
    data->img = NULL;  
    data->game = NULL;  
    data->p_img = NULL; 
    data->bg_img = NULL; 
    init_tile(&data->tile);
    data->mlx_on = NULL; 
    data->map_position = NULL;
    data->cam = malloc(sizeof(t_cam));
    if (!data->cam) {
        err_msg(Y "Failed to allocate memory for cam." RST, 1);
        exit(EXIT_FAILURE);
    }
    init_cam(data->cam);
    init_ray(&data->ray);
    init_obj(&data->obj);
}
