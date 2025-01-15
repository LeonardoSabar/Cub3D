/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:51:54 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/14 23:15:08 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
    if (data->parse_map)
        free_tab((void **)data->parse_map);
    if (data->texinfo.floor)
        free(data->texinfo.floor);
    if (data->texinfo.ceiling)
        free(data->texinfo.ceiling);
    if (data->mapinfo.file)
        free_tab((void **)data->mapinfo.file);
}