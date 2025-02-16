/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:07:17 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/16 06:20:29 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static mlx_texture_t *init_texture(char *path)
{
    mlx_texture_t *texture;
    texture = mlx_load_png(path);
    if (!texture)
        return (err_msg(RED "Failed to load texture" RST, NULL));
    return (texture);
}

void    load_textures(t_game *game)
{
    game->textures->north = init_texture(game->texinfo->north);
    game->textures->south = init_texture(game->texinfo->south);
    game->textures->west = init_texture(game->texinfo->west);
    game->textures->east = init_texture(game->texinfo->east);
}