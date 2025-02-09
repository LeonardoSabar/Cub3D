/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:32:36 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/09 15:32:36 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static void init_images(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        game->obj[i].img.img = mlx_png_file_to_image(game->mlx_on, game->obj[i].img.texture, &game->obj[i].sizes.x, &game->obj[i].sizes.y); // Checar se o mlx_png_file_to_image esta correto
        if (!game->obj[i].img.img)
            return (err_msg("Error\nmlx_png_file_to_image failed\n", ERROR));
        i++;
    }
    game->p_img = mlx_png_file_to_image(game->mlx_on, game->texinfo.path, &game->tile.width, &game->tile.height);
    if (!game->p_img)
        return (err_msg("Error\nmlx_png_file_to_image failed\n", ERROR));
    game->bg_img = mlx_png_file_to_image(game->mlx_on, game->texinfo.path, &game->tile.width, &game->tile.height);
    if (!game->bg_img)
        return (err_msg("Error\nmlx_png_file_to_image failed\n", ERROR));
    // Checar se o mlx_png_file_to_image esta correto
}

static void init_game_static(t_game *game)
{
    if (game->player.dir == 'N')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
        game->player.plane_x = 0;
        game->player.plane_y = 0.66;
    }
    else if (game->player.dir == 'S')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;
        game->player.plane_x = 0;
        game->player.plane_y = -0.66;
    }
    else if (game->player.dir == 'W')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
        game->player.plane_x = -0.66;
        game->player.plane_y = 0;
    }
    else if (game->player.dir == 'E')
    {
        game->player.dir_x = 0;
        game->player.dir_y = 1;
        game->player.plane_x = 0.66;
        game->player.plane_y = 0;
    }
}

static init_minimap(t_game *game)
{
    game->minimap = mlx_new_image(game->mlx_on, 200, 200, 0);
    if (!game->minimap)
        return (err_msg("Error\nmlx_new_image failed\n", ERROR));
    game->minimap->img = mlx_get_data_addr(game->minimap->img, &game->minimap->bpp, &game->minimap->size_l, &game->minimap->endian);
    game->minimap->width = 200;
    game->minimap->height = 200;
    game->minimap->x = 10;
    game->minimap->y = 10;
    game->minimap->color = CYAN;
}

int init_game(t_game *game)
{
    init_game_static(game);
    game->mlx_on = mlx_init();
    if (!game->mlx_on)
        return (err_msg("Error\nmlx_init failed\n", ERROR));
    game->img = mlx_new_image(game->mlx_on, WIDTH, HEIGHT, 0);
    if (!game->img)
        return (err_msg("Error\nmlx_new_image failed\n", ERROR));
    init_images(game);
    init_minimpap(game);
    mlx_loop_hook(game->mlx_on, render_next_frame, game);
    mlx_hook(game->mlx_on->win, 2, 1L << 0, key_press, game);
    mlx_hook(game->mlx_on->win, 3, 1L << 1, key_release, game);
    mlx_hook(game->mlx_on->win, 17, 0, close_game, game);
    mlx_loop(game->mlx_on);
    return (SUCCESS);
}