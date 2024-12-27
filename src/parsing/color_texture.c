/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:24:11 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/27 16:59:33 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static bool	no_digit(char *str)
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

static int *copy_into_rgb_array(char **rgb_to_convert, int *rgb)
{
    int i = 0;

    while (rgb_to_convert[i])
    {
        rgb[i] = ft_atoi(rgb_to_convert[i]);
        if (rgb[i] < 0 || rgb[i] > 255 || no_digit(rgb_to_convert[i]))
        {
            free_tab((void **)rgb_to_convert);
            free(rgb);
            return NULL;
        }
        i++;
    }
    free_tab((void **)rgb_to_convert);
    return rgb;
}



static int	*set_rgb_colors(char *line)
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
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		err_msg("Could not allocate memory", 0);
		return (0);
	}
	return (copy_into_rgb_array(rgb_to_convert, rgb));
}


int fill_color_textures(t_texinfo *textures, char *line, int j)
{
    if (line[j] == 'C' && line[j + 1] && ft_isprint(line[j + 1]))
    {
        if (!textures->ceiling)
        {
            textures->ceiling = set_rgb_colors(line + j + 1);
            if (textures->ceiling == NULL)
                return (err_msg("Invalid ceiling RGB color", 2));
        }
    }
    else if (line[j] == 'F' && line[j + 1] && ft_isprint(line[j + 1]))
    {
        if (!textures->floor)
        {
            textures->floor = set_rgb_colors(line + j + 1);
            if (textures->floor == NULL)
                return (err_msg("Invalid floor RGB color", 2));
        }
    }
    else
        return (err_msg("Invalid floor/ceiling RGB color(s)", 2));
    return (0);
}

