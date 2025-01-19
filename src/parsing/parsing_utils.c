/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:32:37 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/19 20:15:10 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_a_white_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (1);
	else
		return (0);
}

size_t	find_biggest_len(t_mapinfo *map, int i)
{
	size_t	biggest_len;

	biggest_len = ft_strlen(map->file[i]);
	while (map->file[i])
	{
		if (ft_strlen(map->file[i]) > biggest_len)
			biggest_len = ft_strlen(map->file[i]);
		i++;
	}
	return (biggest_len);
}

int	required_rgb_colors(int *color_array)
{
	color_array[3] = 255;
	if (color_array[0] == -1 || color_array[1] == -1 || color_array[2] == -1 || color_array[3] == -1)
		return (ERROR);
	return (SUCCESS);
}

int special_ft_strncmp(const char *str1, const char *str2, size_t n)
{
    while (n > 0)
    {
        if (*str1 == '\r') // Ignora o caractere '\r' na primeira string
        {
            str1++;
            continue; // Avança para a próxima iteração do loop
        }
        
        if (*str2 == '\r') // Ignora o caractere '\r' na segunda string
        {
            str2++;
            continue; // Avança para a próxima iteração do loop
        }

        // Se os caracteres são diferentes, termina a comparação
        if (*str1 != *str2)
            break;

        str1++;
        str2++;
        n--;
    }

    // Verifica se n é zero ou se ambos os ponteiros chegam ao mesmo tempo
    if (n == 0)
        return (0);

    return ((unsigned char)*str1 - (unsigned char)*str2); // Retorna a diferença entre caracteres
}