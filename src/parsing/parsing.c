/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:50:42 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/12 21:18:28 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parsing(t_game *data, char **argv)
{
    if (parse_file(argv[1], true) != 0)
		return (ERROR);
	if (parse_data(argv[1], data) != 0)
		return (ERROR);
	if (get_map_elements(data, data->mapinfo.file) != 0)
		return (ERROR);
	if (parse_map(data, data->map) != 0)
		return (ERROR);
	if (get_map_list_node(data, data->map) != 0)
		return (ERROR);
	if (parse_textures(&data->texinfo) != 0)
		return (ERROR);
	return (SUCCESS);
}