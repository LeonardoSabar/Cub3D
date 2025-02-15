/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:50:42 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/15 20:09:54 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static void	calc_lines_and_columns(t_map *map_position, t_tile *tile)
{
	int		line;
	int		column;
	t_map	*map;

	line = 0;
	column = 0;
	map = map_position;
	while (map)
	{
		if (is_valid_char(map->content) == 1)
		{
			if (line < map->line)
				line++;
			if (column < map->column)
				column++;
		}
		map = map->nxt;
	}
	tile->height = line + 1;
	tile->width = column + 1;
	if (HEIGHT / tile->height >= WIDTH / tile->width)
		tile->base = WIDTH / tile->width;
	else
		tile->base = HEIGHT / tile->height;
}

int	parsing(t_game *data, char **argv)
{
    if (parse_file(argv[1], true) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++++    File  parsed    ++++++++\n" RST); // Retirar
	if (parse_data(argv[1], data) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++++    Data  parsed    ++++++++\n" RST); // Retirar
	if (get_map_elements(data, data->mapinfo.file) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++++ Map elements parsed +++++++\n" RST); // Retirar
	if (parse_map(data, data->map) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n+++++++++    Map parsed    +++++++++\n" RST); // Retirar
	if (get_map_list_node(data, data->map) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n+++++++++   List  filled   +++++++++\n" RST); // Retirar
	if (parse_textures(data->texinfo) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++    Textures  parsed    ++++++\n" RST); // Retirar
	// if (DEBUG == 1)
	// 	printf(G "\n++ Parsing completed successfully ++\n\n" RST); // Retirar
	calc_lines_and_columns(data->map_position, &data->tile);
	//start_cam_infor(data);
	printf("%d --- %d --- %d\n", data->tile.height, data->tile.width, data->tile.base);
	return (SUCCESS);
}
