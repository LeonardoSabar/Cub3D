/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:07:21 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/17 12:28:42 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



static int check_top_or_bottom(char **map_tab, int i, size_t j)
{
    if (!map_tab || !map_tab[i]) 
        return (FAILURE);
    while (map_tab[i][j] && 
           (map_tab[i][j] == ' ' || map_tab[i][j] == '\t' || 
            map_tab[i][j] == '\r' || map_tab[i][j] == '\n' || 
            map_tab[i][j] == '\v' || map_tab[i][j] == '\f'))
        j++;
    if (j >= ft_strlen(map_tab[i])) {
        return (FAILURE);
    }
    while (map_tab[i][j])
    {
        if (map_tab[i][j] == '\r')
		{
            j++;
            continue;
        }
        if (map_tab[i][j] != '1') 
			return (FAILURE);
        j++;
    }
    return (SUCCESS);
}

int	check_map_sides(t_mapinfo *map, char **map_tab)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map_tab, 0, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] == '\r') // resolve problema de '\r' no final da linha // Manter?
			j--;
		if (map_tab[i][j] != '1')
			return (FAILURE);
		i++;
	}
	if (check_top_or_bottom(map_tab, i, 0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}