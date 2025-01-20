/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:30:05 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/20 03:31:58 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	parse_cub_extension(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	return (!ft_strncmp(file + len - 4, ".cub", 4));
}

static bool	parse_xpm_extension(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	return (!special_ft_strncmp(file + len - 4, ".xpm", 4)); // resolver isso, tive que colocar por conta do '\r'
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

int	parse_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(Y "The argument is a directory!" RST, 1));
	if (cub)
	{
		fd = open(arg, O_RDONLY);
		if (fd == -1)
			return (err_msg(Y "Error opening file" RST, 1));
		close(fd);
		if (!parse_cub_extension(arg))
			return (err_msg(Y "Not a .cub file" RST, 1));
	}
	if (!cub && !parse_xpm_extension(arg))
		return (err_msg(Y "Not a .xpm file" RST, 1)); // mudar para png.
	return (0);
}
