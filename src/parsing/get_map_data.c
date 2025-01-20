/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:48:30 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/20 03:10:56 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static int count_map_lines(t_game *data, char **file, int i)
{
    int index_value;
    int j;

    index_value = i;
    while (file[i])
    {
        j = 0;
        while (file[i][j] && 
              (file[i][j] == ' ' || file[i][j] == '\t' || 
               file[i][j] == '\r' || file[i][j] == '\v' || 
               file[i][j] == '\f'))
            j++;
        if (file[i][j] != '1')
            break;
        i++;
    }
    data->mapinfo.index_end_of_map = i;
    return (i - index_value);
}

static int fill_map_tab(t_mapinfo *mapinfo, char **map_tab, int index)
{
    int i;

    i = 0;
    mapinfo->width = find_biggest_len(mapinfo, index);
    while (i < mapinfo->height)
    {
        int j = 0;
        map_tab[i] = malloc(sizeof(char) * (mapinfo->width + 1));
        if (!map_tab[i])
        {
            while (i > 0)
                free(map_tab[--i]);
            return (err_msg(Y "Could not allocate memory" RST, 1));
        }
        while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
        {
            map_tab[i][j] = mapinfo->file[index][j];
            j++;
        }
        map_tab[i][j] = '\0';
        i++;
        index++;
    }
    map_tab[i] = NULL;
    return (SUCCESS);
}

static int get_map_info(t_game *data, char **file, int i)
{
    data->mapinfo.height = count_map_lines(data, file, i);
    data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
    if (!data->map)
        return (err_msg(Y "Could not allocate memory"RST, 1));
    if (fill_map_tab(&data->mapinfo, data->map, i) == FAILURE)
    {
        free(data->map);
        return (FAILURE);
    }
    return (SUCCESS);
}


static void change_space_into_wall(t_game *data)
{
    size_t  j;
    int i = 0;
    while (data->map[i] != NULL)
    {
        j = 0;
        while (data->map[i][j] && 
               (data->map[i][j] == ' ' || 
                data->map[i][j] == '\t' || 
                data->map[i][j] == '\r' || 
                data->map[i][j] == '\v' || 
                data->map[i][j] == '\f'))
            j++;
        while (data->map[i][j])
        {
            if (data->map[i][j] == ' ' && 
                j != ft_strlen(data->map[i]) - 1)
                data->map[i][j] = '1'; 
            j++;
        }
        i++;
    }
}

int create_map(t_game *data, char **file, int i)
{
    if (get_map_info(data, file, i) == FAILURE)
        return (FAILURE);
    change_space_into_wall(data);
    return (SUCCESS);
}