/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:50:42 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/20 16:05:12 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (parse_textures(&data->texinfo) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++    Textures  parsed    ++++++\n" RST); // Retirar
	if (DEBUG == 1)
		printf(G "\n++ Parsing completed successfully ++\n\n" RST); // Retirar
	if (DEBUGHARD == 1)
		print_game_info(*data); // Retirar
	return (SUCCESS);
}