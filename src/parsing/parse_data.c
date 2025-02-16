/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:06:03 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/16 05:06:25 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int get_number_of_lines(char *path)
{
	int fd = open(path, O_RDONLY);
	int line_count = 0;
	char *line;

	if (fd < 0)
		return (err_msg(Y "Error opening file to count lines" RST, 1));
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);

	if (line_count == 0)
		return (err_msg(Y "Empty file" RST, 1));

	return (line_count);
}

static int read_line_to_tab(int row, char *line, t_game *data)
{
	data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (!data->mapinfo.file[row])
	{
		free_tab((void **)data->mapinfo.file);
		return (err_msg(Y "Memory allocation failure" RST, 1));
	}
	ft_strlcpy(data->mapinfo.file[row], line, ft_strlen(line) + 1);
	return (SUCCESS);
}

static int fill_tab(t_game *data)
{
	char *line;
	int row = 0;
	if (!data->mapinfo.file || data->mapinfo.line_count == 0)
		return (err_msg(Y "Map file is not allocated or empty" RST, 1));

	while ((line = get_next_line(data->mapinfo.fd)))
	{
		if (read_line_to_tab(row, line, data) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		free(line);
		row++;
	}
	data->mapinfo.file[row] = NULL;
	return (SUCCESS);
}

int parse_data(char *path, t_game *data)
{
	data->mapinfo.line_count = get_number_of_lines(path);
	if (data->mapinfo.line_count <= 0)
		return (ERROR);
	data->mapinfo.file = ft_calloc(data->mapinfo.line_count + 1, sizeof(char *));
	if (!data->mapinfo.file)
		return (err_msg(Y "Memory allocation failure" RST, 1));
	data->mapinfo.fd = open(path, O_RDONLY);
	if (data->mapinfo.fd < 0)
	{
		free_tab((void **)data->mapinfo.file);
		return (err_msg(Y "Error opening file" RST, 1));
	}
	if (fill_tab(data) == ERROR)
	{
		close(data->mapinfo.fd);
		free_tab((void **)data->mapinfo.file);
		return (ERROR);
	}
	close(data->mapinfo.fd);
	return (SUCCESS);
}
