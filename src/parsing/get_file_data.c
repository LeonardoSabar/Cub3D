/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:52:25 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/16 18:53:17 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int print_texture(t_texinfo *textures)
{
	printf("\nNorth: %s\n", textures->north);
	printf("South: %s\n", textures->south);
	printf("West: %s\n", textures->west);
	printf("East: %s\n", textures->east);
	return (0);
}
static char *get_texture_path(char *line, int j)
{
    int len;
    int i;
    char *path;

    while (line[j] && (line[j] == ' ' || line[j] == '\t'))
        j++;
    len = j;
    while (line[len] && (line[len] != ' ' && line[len] != '\t' && line[len] != '\n'))
        len++;
    path = malloc(sizeof(char) * (len - j + 1));
    if (!path)
        return (NULL);
    i = 0;
    while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
        path[i++] = line[j++];
    path[i] = '\0';
    while (line[j] && (line[j] == ' ' || line[j] == '\t'))
        j++;
    
    if (line[j] && line[j] != '\n')
    {
        free(path);
        return (NULL);
    }
    return (path);
}

static int fill_direction_textures(t_texinfo *textures, char *line, int j)
{
    size_t line_length;
	
	line_length = ft_strlen(line); 
    if ((size_t)(j + 2) >= line_length || !ft_isprint(line[j + 2]))
        return (2);
    if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
        textures->north = get_texture_path(line, j + 2);
    else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
        textures->south = get_texture_path(line, j + 2);
    else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
        textures->west = get_texture_path(line, j + 2);
    else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
        textures->east = get_texture_path(line, j + 2);
    else
	{
		if (textures->north && textures->south && textures->west && textures->east)
            return (0);
        return (2);
	}
	return (0);
}


static int print_floor_ceiling(t_texinfo *textures)
{
	if (textures->ceiling)
		printf("\nCeiling: %d, %d, %d, %d(Transparence)\n", textures->ceiling[0], textures->ceiling[1], textures->ceiling[2], textures->ceiling[3]);
	if (textures->floor)
		printf("Floor: %d, %d, %d, %d(Transparence)\n", textures->floor[0], textures->floor[1], textures->floor[2], textures->floor[3]);
	return (0);
}

static int ignore_whitespaces_get_info(t_game *data, char **map, int i, int j)
{
	printf(M "\nMap[%d][%d]: %c\n" RST, i, j, map[i][j]); // retirar
    while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
        j++;
    if (map[i][j] == '\0') 
        return (4);

    if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
    {
        if (map[i][j + 1] && ft_isprint(map[i][j + 1]))
        {
            if (fill_direction_textures(&data->texinfo, map[i], j) == 2)
                return (err_msg("Invalid texture(s)", 1));
            printf(RED "Entrou!!!" RST); // Depuração
            return (3);
        }
        if (map[i][j] == 'F' || map[i][j] == 'C')
        {
            if (fill_color_textures(&data->texinfo, map[i], j) == 2)
                return (1);
            return (3);
        }
    }
    else if (ft_isdigit(map[i][j]))
    {
        if (create_map(data, map, i) == 1)
            return (err_msg("Map description is either wrong or incomplete", 1));
        return (0);
    }
    return (4);
}


int	get_file_data(t_game *data, char **map)
{
	int	i;
	int	j;
	int	ret;

	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = ignore_whitespaces_get_info(data, map, i, j);
			if (ret == 3)
				break ;
			else if (ret == 1)
				return (1);
			else if (ret == 0)
			{
				print_texture(&data->texinfo); // retirar
				print_floor_ceiling(&data->texinfo); // retirar
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

