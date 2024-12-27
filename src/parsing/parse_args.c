/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:30:05 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/27 00:56:49 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	parse_extention(char *file)
{
    bool ret;

    ret = false;
	if (!ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
        ret = true;
    return (ret);
}

static bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

int	parse_file(char *arg)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg("Is a directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(strerror(errno), 1));
	close(fd);
	if (!parse_extention(arg))
		return (err_msg("Not a .cub file", 1));
	return (0);
}


/*
void parse_textures(t_data *data, char *line)
{
    if (ft_strncmp(line, "NO", 2) == 0)  // Norte
    {
        data->textures.north = ft_strdup(line + 3); // Copia a string após "NO "
        if (data->textures.north == NULL)
        {
            ft_printf("Error: Memory allocation failed for north texture\n");
            exit(1);
        }
    }
    else if (ft_strncmp(line, "SO", 2) == 0) // Sul
    {
        data->textures.south = ft_strdup(line + 3);
        if (data->textures.south == NULL)
        {
            ft_printf("Error: Memory allocation failed for south texture\n");
            exit(1);
        }
    }
    else if (ft_strncmp(line, "WE", 2) == 0) // Oeste
    {
        data->textures.west = ft_strdup(line + 3);
        if (data->textures.west == NULL)
        {
            ft_printf("Error: Memory allocation failed for west texture\n");
            exit(1);
        }
    }
    else if (ft_strncmp(line, "EA", 2) == 0) // Leste
    {
        data->textures.east = ft_strdup(line + 3);
        if (data->textures.east == NULL)
        {
            ft_printf("Error: Memory allocation failed for east texture\n");
            exit(1);
        }
    }
    else
    {
        ft_printf("Error: Invalid texture specification '%s'\n", line);
        exit(1);
    }
}

void parse_colors(t_data *data, char *line)
{
	if (line[0] == 'F')
	else if (line[0] == 'C')
}

int is_blank_line(const char *line)
{
    while (*line)
    {
        if (!isspace(*line)) 
            return 0; 
        line++;
    }
    return (1); 
}

void	parse_file(char *file)
{
	int fd;
	int i;
	int valid_line;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0) // usar gnl da 42
	{
		valid_line = is_blank_line(line);
		if (validity == 1)
        {
            parse_config_or_textures(data, line); // Processa texturas ou cores
            if (line[0] == '1' || line[0] == '0')
                i++; // Incrementa a contagem de linhas do mapa
        }
        else if (validity == -1)
        {
            ft_printf("Error: Invalid line in map file '%s'\n", line);
            free(line);
            exit(1);
        }
        free(line);
	}
	if (i == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	close(fd);
}
*/