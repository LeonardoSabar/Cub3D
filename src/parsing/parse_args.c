/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:30:05 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/11 16:39:17 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	parse_extension(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	return (!ft_strncmp(file + len - 4, ".cub", 4));
}

static bool	is_dir(char *arg)
{
	int fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (true);
	}
	return (false);
}

int	parse_file(char *arg)
{
	int	fd;

	if (!parse_extension(arg))
		return (err_msg("Not a .cub file", 1));
	if (is_dir(arg))
		return (err_msg("Is a directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			return (err_msg("Permission denied to open the file.", 1));
		else if (errno == ENOENT)
			return (err_msg("File does not exist.", 1));
		else
			return (err_msg(strerror(errno), 1));
	}
	close(fd);
	return (0);
}
