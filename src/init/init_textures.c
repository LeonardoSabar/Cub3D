/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:07:17 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/16 06:29:10 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static mlx_texture_t *load_texture(char *path)
{
    mlx_texture_t *texture;
    texture = mlx_load_png(path);
    if (!texture)
        err_msg(RED "Failed to load texture" RST, 1); // Arrumar o exit para esse erro!
    return (texture);
}

void    init_textures(t_game *game)
{
    game->textures->north = load_texture(game->texinfo->north);
    game->textures->south = load_texture(game->texinfo->south);
    game->textures->west = load_texture(game->texinfo->west);
    game->textures->east = load_texture(game->texinfo->east);
}