/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:30:08 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/27 00:55:47 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	count_map_lines(t_game *data, char **file, int i)
{
	int	index_value;
	int	j;

	index_value = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->mapinfo.index_end_of_map = i;
	return (i - index_value);
}

static int	fill_map_tab(t_mapinfo *mapinfo, char **map_tab, int index)
{
	int		i;
	int		j;

	mapinfo->width = find_biggest_len(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (mapinfo->width + 1));
		if (!map_tab[i])
			return (err_msg("Could not allocate memory", 1));
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map_tab[i][j] = mapinfo->file[index][j];
			j++;
		}	
		while (j < mapinfo->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (0);
}

static int	get_map_info(t_game *data, char **file, int i)
{
	data->mapinfo.height = count_map_lines(data, file, i);
	data->parse_map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (err_msg("Could not allocate memory", 1));
	if (fill_map_tab(&data->mapinfo, data->parse_map, i) == 1)
		return (1);
	return (0);
}

static void	change_space_into_wall(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parse_map[i])
	{
		j = 0;
		while (data->parse_map[i][j] == ' ' || data->parse_map[i][j] == '\t'
		|| data->parse_map[i][j] == '\r'
		|| data->parse_map[i][j] == '\v' || data->parse_map[i][j] == '\f')
			j++;
		while (data->parse_map[i][++j])
		{
			if (data->parse_map[i][j] == ' '
				&& j != data->parse_map[i][ft_strlen(data->parse_map[i]) - 1])
				data->parse_map[i][j] = '1';
		}
		i++;
	}
}

int	create_map(t_game *data, char **file, int i)
{
	if (get_map_info(data, file, i) == 1)
		return (1);
	change_space_into_wall(data);
	return (0);
}