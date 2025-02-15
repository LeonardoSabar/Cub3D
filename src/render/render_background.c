/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:54:04 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/13 14:10:48 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_background(t_game *gm)
{
    int max_h;
    int i;
    int j;

    gm->bg_img = mlx_new_image(gm->mlx_on, WIDTH, HEIGHT);
    max_h = HEIGHT / 2;
    j = 0;
    while (j < HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            if (j < max_h)
                mlx_put_pixel(gm->bg_img, i, j, reverse_bytes(gm->texinfo->hex_ceiling));
            else
                mlx_put_pixel(gm->bg_img, i, j, reverse_bytes(gm->texinfo->hex_floor));
            i++;
        }
        j++;
    }
    mlx_image_to_window(gm->mlx_on, gm->bg_img, 0, 0);
    gm->bg_img->instances[0].z = true;
}