/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:45:24 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/19 21:36:56 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg(Y "Invalid RGB color value" RST, FAILURE));
		i++;
	}
	return (SUCCESS);
}

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;
	int				t;

	rgb_tab[3] = 255;
	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	t = rgb_tab[3];
	
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff) + ((t & 0xff) << 24);
	return (result);
}
static int print_floor_ceiling(t_texinfo *textures)
{
	if (textures->ceiling)
		printf(Y"\nCeiling: %d, %d, %d, %d(Transparence) parsed!\n", textures->ceiling[0], textures->ceiling[1], textures->ceiling[2], textures->ceiling[3]);
	if (textures->floor)
		printf("Floor: %d, %d, %d, %d(Transparence) parsed!\n\n"RST, textures->floor[0], textures->floor[1], textures->floor[2], textures->floor[3]);
	return (0);
}

int	parse_textures(t_texinfo *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (err_msg(Y "Missing texture path" RST, FAILURE));
	if (!textures->floor || !textures->ceiling)
		return (err_msg(Y "Missing color value" RST, FAILURE));
	if (parse_file(textures->north, false) == FAILURE
		|| parse_file(textures->south, false) == FAILURE
		|| parse_file(textures->west, false) == FAILURE
		|| parse_file(textures->east, false) == FAILURE
		|| check_valid_rgb(textures->floor) == FAILURE
		|| check_valid_rgb(textures->ceiling) == FAILURE)
		return (FAILURE);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
	if (DEBUGHARD == 1) // retirar
		print_floor_ceiling(textures);
	return (SUCCESS);
}