/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:24:11 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/19 04:25:10 by leobarbo         ###   ########.fr       */
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
	if (DEBUGHARD == 1) // retirar
    	printf(O"\nLine: %c processed\n" RST, line[j]); // retirar
	if (line[j] == 'C')
	{
		textures->ceiling = parse_rgb_color(line + j + 1);
        textures->ceiling[3] = 255;
		if (textures->ceiling == 0)
			return (err_msg(Y "Invalid ceiling RGB color" RST, 2));
	}
	else if (line[j] == 'F')
	{
		textures->floor = parse_rgb_color(line + j + 1);
        textures->floor[3] = 255;
		if (textures->floor == 0)
			return (err_msg(Y "Invalid floor RGB color" RST, 2));
	}
	else
		return (err_msg(Y "Invalid floor/ceiling RGB color(s)" RST, 2));
	return (SUCCESS);
}


/*
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
        printf(Y "RGB[%d]: %d\n" RST, i, rgb[i]); // retirar
        if (rgb[i] < 0 || rgb[i] > 255 || no_digit(rgb_to_convert[i]))
        {
            free_tab((void **)rgb_to_convert);
            free(rgb);
            return (NULL);
        }
        i++;
    }
    free_tab((void **)rgb_to_convert);
    return (rgb);
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
	rgb = malloc(sizeof(int) * 4);
	if (!rgb)
	{
		err_msg("Could not allocate memory", 0);
		return (0);
	}
	return (copy_into_rgb_array(rgb_to_convert, rgb));
}

int fill_color_textures(t_texinfo *textures, char *line, int j)
{
    printf("\nLine: %c\n", line[j]); // retirar
    if (line[j] == 'F' && line[j + 1] && ft_isprint(line[j + 1]))
    {
        printf(RED "Entrou no F\n" RST); // retirar
        if (!textures->floor)
        {
            textures->floor = set_rgb_colors(line + j + 1);
            textures->floor[3] = 255;
            if (textures->floor == NULL)
                return (err_msg("Invalid floor RGB color", 2));
        }
    }
    else if (line[j] == 'C' && line[j + 1] && ft_isprint(line[j + 1]))
    {
        if (!textures->ceiling)
        {
            textures->ceiling = set_rgb_colors(line + j + 1);
            textures->ceiling[3] = 255;
            if (textures->ceiling == NULL)
                return (err_msg("Invalid ceiling RGB color", 2));
        }
    }
    else
        return (err_msg("Invalid floor/ceiling RGB color(s)", 2));
    return (0);
}

*/