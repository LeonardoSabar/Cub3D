/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:39:49 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/17 12:26:01 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int check_map_elements(t_game *data, char **map_tab)
{
    int i;
    int j;

	i = 0;
    data->player.dir = '0';
    while (map_tab[i] != NULL)
    {
        j = 0;
        while (map_tab[i][j])
        {
            while (map_tab[i][j] && (map_tab[i][j] == ' ' || 
                   map_tab[i][j] == '\t' || map_tab[i][j] == '\r' || 
                   map_tab[i][j] == '\v' || map_tab[i][j] == '\f'))
                j++;
            if (map_tab[i][j] == '\0')
                break;
            if (!(ft_strchr("10NSEW", map_tab[i][j])))
                return (err_msg(Y "Invalid map element" RST, FAILURE));
            if (ft_strchr("NSEW", map_tab[i][j])) 
            {
                if (data->player.dir != '0') 
                    return (err_msg(Y "Player position is not unique" RST, FAILURE));
                data->player.dir = map_tab[i][j];
			}
            j++;
        }
        i++;
    }
    return (SUCCESS);
}

static int	check_position_is_valid(t_game *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	 if (ft_strlen(map_tab[i - 1]) < (size_t)j || 
        ft_strlen(map_tab[i + 1]) < (size_t)j ||
        is_a_white_space(map_tab[i][j - 1]) == SUCCESS ||
        is_a_white_space(map_tab[i][j + 1]) == SUCCESS ||
        is_a_white_space(map_tab[i - 1][j]) == SUCCESS ||
        is_a_white_space(map_tab[i + 1][j]) == SUCCESS)
        return (FAILURE);

    return (SUCCESS);
}

static int	check_player_position(t_game *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (err_msg(Y "Player position is not defined" RST, FAILURE));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_position_is_valid(data, map_tab) == FAILURE)
		return (err_msg(Y "Player position is not valid" RST, FAILURE));
	return (SUCCESS);
}

static int	check_map_is_at_the_end(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	parse_map(t_game *data, char **map_tab)
{
	if (!data->map)
		return (err_msg(Y "Map is not defined" RST, FAILURE));
	if (check_map_sides(&data->mapinfo, map_tab) == FAILURE)
		return (err_msg(Y "Map is not surrounded by walls" RST, FAILURE));
	if (data->mapinfo.height < 3)
		return (err_msg(Y "Map is too small" RST, FAILURE));
	if (check_map_elements(data, map_tab) == FAILURE)
		return (FAILURE);
	if (check_player_position(data, map_tab) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(&data->mapinfo) == FAILURE)
		return (err_msg(Y "Map is not at the end of the file" RST, FAILURE));
	return (SUCCESS);
}
