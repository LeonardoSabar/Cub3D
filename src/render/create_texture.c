/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:21:12 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/12 23:37:41 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	if (x > img->width || y > img->height)
		return ;
	mlx_put_pixel(img, x, y, color);
}

static mlx_texture_t	*construct_texture(char *png)
{
	mlx_texture_t	*tmp;
	int32_t			fd;
	int32_t			len;

	len = ft_strlen(png);
	if (len < 4 && ft_strncmp(&png[len - 4], ".png", 5) != 0)
		return (ft_printf("Invalid .png texture"), NULL);
	fd = open(png, O_RDONLY, 0644);
	if (fd < 1)
		return (ft_printf("Impossible to load texture"), NULL);
	close(fd);
	tmp = mlx_load_png(png);
	if (!tmp)
		return(ft_printf("Failed to load texture"), NULL);
	return (tmp);
}

t_texture   *create_texture(t_game *gm)
{
    t_texture   *texture;
    
    texture = malloc(sizeof(t_texture));
    texture->north = construct_texture(gm->texinfo->north);
    texture->south = construct_texture(gm->texinfo->south);
    texture->west = construct_texture(gm->texinfo->west);
    texture->east = construct_texture(gm->texinfo->east);
	if (!texture->north || !texture->south || !texture->west || !texture->east)
		return (NULL);
    return (texture);
}