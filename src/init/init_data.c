/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:01:44 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/27 17:05:24 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void init_ray(t_ray *ray)
{
	ray->ray_ngl = 0;
	ray->distance = 0;
	ray->flag = 0;
}

static void init_tile(t_tile *tile)
{
	tile->base = 0;
	tile->width = 0;
	tile->height = 0;
}

static void init_cam(t_cam *cam)
{
	cam->plr_x = 0;
	cam->plr_y = 0;
	cam->rotation = 0;
	cam->l_r = 0;
	cam->angle = 0;
	cam->fov_plr = 0;
}

static void init_map(t_map *map)
{
	map->line = 0;
	map->column = 0;
	map->content = 0;
	map->nxt = NULL;
	map->prv = NULL;
}

static void init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->height = 0;
}

static void init_img(t_img *img)
{
    img->texture = NULL;
    img->img = NULL;
}

static void init_render_img(t_r_img *render_img)
{
    render_img->x = 0;
    render_img->y = 0;
    render_img->z = 0;
}

static void init_object(t_obj *obj)
{
    obj->onoff = 0;
    init_img(&obj->img);
    init_render_img(&obj->sizes);
}

static void init_texinfo(t_texinfo *texinfo)
{
    texinfo->north = NULL; 
    texinfo->south = NULL;
    texinfo->west = NULL;
    texinfo->east = NULL;
    texinfo->floor = NULL;
    texinfo->ceiling = NULL;
    texinfo->hex_floor = 0;
    texinfo->hex_ceiling = 0;
    texinfo->size = 0;
    texinfo->index = 0;
    texinfo->step = 0.0;
    texinfo->pos = 0.0;
    texinfo->x = 0;
    texinfo->y = 0;
}

void init_data(t_game *data)
{
    data->is_horizon = 0;
    data->parse_map = NULL;
    data->img = NULL;
    data->game = NULL;
    data->p_img = NULL;
    data->bg_img = NULL;
    data->mlx_on = NULL;
    init_ray(&data->ray);
    init_tile(&data->tile);
    init_cam(data->cam);
    init_map(data->map);
    init_mapinfo(&data->mapinfo);
    init_texinfo(&data->texinfo);
    init_object(&data->obj);
}
