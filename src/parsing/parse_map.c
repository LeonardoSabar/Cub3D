/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:39:49 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/14 01:35:14 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_map(t_game *data, char **map_tab)
{
	if (!data->map)
		return (err_msg("Map is not defined", FAILURE));
	if (check_map_sides(&data->mapinfo, map_tab) == FAILURE)
		return (err_msg("Map is not surrounded by walls", FAILURE));
	if (data->mapinfo.height < 3)
		return (err_msg("Map is too small", FAILURE));
	if (check_map_elements(data, map_tab) == FAILURE)
		return (FAILURE);
	if (check_player_position(data, map_tab) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(&data->mapinfo) == FAILURE)
		return (err_msg("Map is not at the end of the file", FAILURE));
	return (SUCCESS);
}
