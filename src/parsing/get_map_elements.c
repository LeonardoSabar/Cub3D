/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:52:25 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/19 20:56:52 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int print_floor_ceiling(t_texinfo *textures)
{
	if (textures->ceiling)
		printf( O "\nCeiling: %d, %d, %d, %d(Transparence)\n", textures->ceiling[0], textures->ceiling[1], textures->ceiling[2], textures->ceiling[3]);
	if (textures->floor)
		printf("Floor: %d, %d, %d, %d(Transparence)\n" RST, textures->floor[0], textures->floor[1], textures->floor[2], textures->floor[3]);
	return (0);
}

static int print_texture(t_texinfo *textures) // Função para Debug // Retirar
{
	printf(O"\nNorth: %s\n" RST, textures->north);
	printf(O"South: %s\n" RST, textures->south);
	printf(O"West: %s\n" RST, textures->west);
	printf(O"East: %s\n" RST, textures->east);
	return (0);
}


static int print_map(t_game *data) // Função para Debug // Retirar
{
    int i;
    int j;

    i = 0;
    printf("\nMap:\n");
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            printf(BGCYN "%c" RST, data->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return (0);
}



static char *parse_texture_path(char *line, int j)
{
    int len;
    int i;
    char *path;

    while (line[j] && (line[j] == ' ' || line[j] == '\t' || line[j] == '\r'))
        j++;
    len = j;
    while (line[len] && (line[len] != ' ' && line[len] != '\t' && line[len] != '\n' && line[len] != '\r'))
        len++;
    path = malloc(sizeof(char) * (len - j + 3));
    if (!path)
        return (NULL);
    path[0] = '.';
    path[1] = '/';
    i = 2;
    while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n' && line[j] != '\r'))
        path[i++] = line[j++];
    path[i] = '\0';
    while (line[j] && (line[j] == ' ' || line[j] == '\t' || line[j] == '\r'))
        j++;
    if (line[j] && line[j] != '\n')
    {
        free(path);
        return (NULL);
    }
    return (path);
}

static int assign_direction_textures(t_texinfo *textures, char *line, int j)
{
    size_t line_length;
	
	line_length = ft_strlen(line); 
    if ((size_t)(j + 2) >= line_length || !ft_isprint(line[j + 2]))
        return (2);
    while (line[j] == ' ' || line[j] == '\t') // retirar
        j++; // retirar
    if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
        textures->north = parse_texture_path(line, j + 2);
    else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
        textures->south = parse_texture_path(line, j + 2);
    else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
        textures->west = parse_texture_path(line, j + 2);
    else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
        textures->east = parse_texture_path(line, j + 2);
    else
	{
		if (textures->north && textures->south && textures->west && textures->east)
            return (0);
        return (2);
	}
	return (0);
}


static int parse_map_info(t_game *data, char **map, int i, int j)
{
    while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
        j++;
    if (map[i][j] == '\0') 
        return (4);
    if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
    {
        if (map[i][j] == 'F' || map[i][j] == 'C')
        {
            if (set_floor_and_ceiling_colors(&data->texinfo, map[i], j) == 2)
                return (ERROR);
            return (3);
        }
        if (map[i][j + 1] && ft_isprint(map[i][j + 1]))
        {
            if (assign_direction_textures(&data->texinfo, map[i], j) == 2)
                return (err_msg(Y "Invalid texture(s)" RST, ERROR));
            return (3);
        }
    
    }
    else if (ft_isdigit(map[i][j]))
    {
        if (create_map(data, map, i) == ERROR)
            return (err_msg(Y "Map description is either wrong or incomplete" RST, ERROR));
        if (DEBUGHARD == 1) // retirar
            print_map(data); // retirar
        return (SUCCESS);
    }
    return (4);
}


int	get_map_elements(t_game *data, char **map)
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
            ret = parse_map_info(data, map, i, j);
			if (ret == 3)
				break ;
			else if (ret == ERROR)
				return (ERROR);
			else if (ret == SUCCESS)
			{
                if (DEBUGHARD == 1) // retirar
				    print_texture(&data->texinfo); // retirar
                if (DEBUGHARD == 1) // retirar
				    print_floor_ceiling(&data->texinfo); // retirar
				return (SUCCESS);
			}
			j++;
		}
		i++;
	}
    return (SUCCESS);
}