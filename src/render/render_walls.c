/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:15:05 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/10 17:43:38 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void my_mlx_pixel_put(t_game *gm, int x, int y, int color)
// {
// 	if (x < 0)
// 		return ;
// 	else if (x >= WIDTH)
// 		return ;
// 	if (y < 0)
// 		return ;
// 	else if (y >= HEIGHT)
// 		return ;
// 	mlx_put_pixel(gm->game, x, y, color);
// }

// static int	get_color(t_game *gm, int flag)
// {
// 	gm->ray.ray_ngl = nor_angle(gm->ray.ray_ngl);
// 	if (flag == 0)
// 	{
// 		if (gm->ray.ray_ngl > M_PI / 2 && gm->ray.ray_ngl < 3 * (M_PI / 2))
// 			return (0xB5B5B5FF);
// 		else
// 			return (0xB5B5B5FF);
// 	}
// 	else
// 	{
// 		if (gm->ray.ray_ngl > 0 && gm->ray.ray_ngl < M_PI)
// 			return (0xF5F5F5FF);void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
// 		else
// 			return (0xF5F5F5FF);
// 	}
// }

// void draw_wall(t_game *gm, int ray, int t_pix, int b_pix)
// {
// 	int color;

// 	color = get_color(gm, gm->ray.flag);
// 	while (t_pix < b_pix)
// 		my_mlx_pixel_put(gm, ray, t_pix++, color);
// }

// void render_wall(t_game *gm, int ray)
// {
// 	double	wall_h;
// 	double	b_pix;
// 	double	t_pix;

// 	gm->ray.distance *= cos(nor_angle(gm->ray.ray_ngl - gm->cam->angle));
// 	wall_h = (gm->tile.base / gm->ray.distance) * ((WIDTH / 2) / tan(gm->cam->fov_plr / 2));
// 	b_pix = (HEIGHT / 2) + (wall_h / 2);
// 	t_pix = (HEIGHT / 2) - (wall_h / 2);
// 	if (b_pix > HEIGHT)
// 		b_pix = HEIGHT;
// 	if (t_pix < 0)
// 		t_pix = 0;
// 	draw_wall(gm, ray, t_pix, b_pix);
// }
// ---------------------------------------------------------------
// static double	get_x_o(mlx_texture_t *texture, t_game *gm)
// {
// 	double	x;
// 	double	width;

// 	width = (double) texture->width;
// 	if (gm->texinfo.x)
// 		x = fmodf((gm->texinfo.x * (width / gm->tile.base)), width);
// 	else
// 		x = fmodf((gm->texinfo.x * (width / gm->tile.base)), width);
// 	if (texture == gm->texinfo.south || texture == gm->texinfo.west)
// 		return (width - x);
// 	return (x);
// }

// void	draw_wall(t_game *gm, int t_pix, int b_pix, double wall_h)
// {
// 	double			x;
// 	double			y;
// 	mlx_texture_t	*texture;
// 	uint32_t		*arr;
// 	double			factor;

// 	texture = get_texture(gm);
// 	arr = (uint32_t *)texture->pixels;
// 	factor = (double)texture->height / wall_h;
// 	x = get_x_o(texture, gm);
// 	y = (t_pix - ((double) gm->img->height / 2) + (wall_h / 2)) * factor;
// 	if (y < 0)
// 		y = 0;
// 	while (t_pix < b_pix)
// 	{
// 		my_mlx_pixel_put(gm, gm->texinfo.index, t_pix++,
// 			reverse_bytes(arr[(int) y * texture->width + (int) x]));
// 		y += factor;
// 	}
// }

// void	render_wall(t_game *gm, int ray)
// {
// 	float	wall_h;
// 	float	b_pix;
// 	float	t_pix;

// 	gm->ray.distance *= cos(nor_angle(gm->ray.ray_ngl - gm->cam->angle));
// 	wall_h = (gm->tile.base / gm->ray.distance) * (((float) gm->img->width / 2)
// 			/ tan(gm->cam->fov_plr / 2));
// 	b_pix = ((double) gm->img->height / 2) + (wall_h / 2);
// 	t_pix = ((double) gm->img->height / 2) - (wall_h / 2);
// 	if (b_pix > gm->img->height)
// 		b_pix = gm->img->height;
// 	if (t_pix < 0)
// 		t_pix = 0;
// 	gm->texinfo.index = ray;
// 	draw_wall(gm, t_pix, b_pix, wall_h);
// }

// void	raycast(t_game *gm)
// {
// 	double		h_inter;
// 	double		v_inter;
// 	uint32_t	ray;

// 	ray = 0;
// 	gm->ray.ray_ngl = gm->cam->angle- (gm->cam->fov_plr / 2);
// 	while (ray < WIDTH)
// 	{
// 		v_inter = get_v_inter(gm, nor_angle(gm->ray.ray_ngl));
// 		h_inter = get_h_inter(gm, nor_angle(gm->ray.ray_ngl));
// 		if (v_inter < h_inter)
// 			gm->ray.distance = get_v_inter(gm, nor_angle(gm->ray.ray_ngl));
// 	}
// 	while (ray < gm->img->width)
// 	{
// 		v_inter = get_v_inter(gm, nor_angle(gm->ray.ray_ngl));
// 		h_inter = get_h_inter(gm, nor_angle(gm->ray.ray_ngl));
// 		if (v_inter < h_inter)
// 			gm->ray.distance = get_v_inter(gm, nor_angle(gm->ray.ray_ngl));
// 		else
// 		{
// 			gm->ray.distance = get_h_inter(gm, nor_angle(gm->ray.ray_ngl));
// 			gm->ray.flag = 1;
// 		}
// 		render_wall(gm, ray++);
// 		gm->ray.ray_ngl += ((double) gm->cam->fov_plr / gm->img->width);
// 	}
// }

mlx_texture_t    *get_texture(t_game *gm)
{
	gm->ray.ray_ngl = nor_angle(gm->ray.ray_ngl);
	if (gm->ray.info->y)
	{
		if (v_unit_circle(gm->ray.ray_ngl))
			return (gm->texinfo.tex.west);
		return (gm->texinfo.tex.east);
	}
	if (h_unit_circle(gm->ray.ray_ngl))
		return (gm->texinfo.tex.south);
	return (gm->texinfo.tex.north);
}

static double	get_x_o(mlx_texture_t *texture, t_game *gm)
{
	double	x;
	double	width;

	width = (double) texture->width;
	if (gm->ray.info->x)
		x = fmodf((gm->ray.info->x * (width / gm->tile.base)), width);
	else
		x = fmodf((gm->ray.info->y * (width / gm->tile.base)), width);
	if (texture == gm->texinfo.tex.south || texture == gm->texinfo.tex.west)
		return (width - x);
	return (x);
}

void	draw_wall2(t_game *gm, int t_pix, int b_pix, double wall_h)
{
	double			x;
	double			y;
	mlx_texture_t	*texture;
	uint32_t		*arr;
	double			factor;

	texture = get_texture(gm);
	arr = (uint32_t *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x = get_x_o(texture, gm);
	y = (t_pix - ((double) gm->img->height / 2) + (wall_h / 2)) * factor;
	if (y < 0)
		y = 0;
	while (t_pix < b_pix)
	{
		put_pixel(gm->img, gm->ray.info->index, t_pix++,
			reverse_bytes(arr[(int) y * texture->width + (int) x]));
		y += factor;
	}
}

void	render_wall(t_game *gm, int ray)
{
	float	wall_h;
	float	b_pix;
	float	t_pix;

	gm->ray.distance *= cos(nor_angle(gm->ray.ray_ngl - gm->cam->angle));
	wall_h = (gm->tile.base / gm->ray.distance) * (((float) gm->img->width / 2)
			/ tan(gm->cam->fov_plr / 2));
	b_pix = ((double) gm->img->height / 2) + (wall_h / 2);
	t_pix = ((double) gm->img->height / 2) - (wall_h / 2);
	if (b_pix > gm->img->height)
		b_pix = gm->img->height;
	if (t_pix < 0)
		t_pix = 0;
	gm->ray.info->index = ray;
	draw_wall2(gm, t_pix, b_pix, wall_h);
}