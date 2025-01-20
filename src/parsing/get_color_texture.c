/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:24:11 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/20 03:10:47 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	is_all_non_numeric(char *str)
{
	int		i;
	bool	found_no_digit;

	i = 0;
	found_no_digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			found_no_digit = false;
		i++;
	}
	return (found_no_digit);
}

static int	*convert_to_rgb_array(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || is_all_non_numeric(rgb_to_convert[i]) == true)
		{
			free_tab((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	free_tab((void **)rgb_to_convert);
	return (rgb);
}

static int	*parse_rgb_color(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		free_tab((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
	{
		err_msg(Y "Could not allocate memory" RST, 0);
		return (0);
	}
	return (convert_to_rgb_array(rgb_to_convert, rgb));
}

int	set_floor_and_ceiling_colors(t_texinfo *textures, char *line, int j)
{
	if (line[j] == 'C')
	{
		textures->ceiling = parse_rgb_color(line + j + 1);
		if (textures->ceiling == 0) 
			return (err_msg(Y "Invalid ceiling RGB color" RST, 2));
	}
	else if (line[j] == 'F')
	{
		textures->floor = parse_rgb_color(line + j + 1);
		if (textures->floor == 0)
			return (err_msg(Y "Invalid floor RGB color" RST, 2));
	}
	else
		return (err_msg(Y "Invalid floor/ceiling RGB color(s)" RST, 2));
	return (SUCCESS);
}
