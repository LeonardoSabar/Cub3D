/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:51:54 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/16 06:35:39 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
/*
static void	delete_textures(t_game *gm)
{
	if (gm->texinfo->tex->north)
    mlx_delete_texture(gm->texinfo->tex->north);
	if (gm->texinfo->tex->south)
    mlx_delete_texture(gm->texinfo->tex->south);
	if (gm->texinfo->tex->east)
    mlx_delete_texture(gm->texinfo->tex->east);
	if (gm->texinfo->tex->west)
    mlx_delete_texture(gm->texinfo->tex->west);
}
*/

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
/*
void free_resources(t_game *data)
{
    t_map *current;
    t_map *tmp;
    
    if (data->cam)
    free(data->cam);
    current = data->map_position;
    while (current)
    {
        tmp = current->nxt;
        free(current);
        current = tmp;
    }
    delete_textures(data);
    if (data->parse_map)
    free_tab((void **)data->parse_map);
    if (data->texinfo->floor)
    free(data->texinfo->floor);
    if (data->texinfo->ceiling)
    free(data->texinfo->ceiling);
    if (data->mapinfo.file)
    free_tab((void **)data->mapinfo.file);
}
*/