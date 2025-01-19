/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:50:42 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/19 17:14:38 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int print_map(t_game *data) // Função para Debug // Retirar
{
	if (data == NULL || data->mapinfo.file == NULL)
        return -1;
	for (int i = 0; i < data->mapinfo.line_count; i++)
    {
		if (data->mapinfo.file[i] != NULL)
			printf("%s\n", data->mapinfo.file[i]);
    }
    return 0;
}

static int print_map_position(t_game *data) // Função para Debug // Retirar
{
    if (data == NULL || data->map_position == NULL) 
        return -1; 

    t_map *current = data->map_position;

	printf(O "\n   ************ Printing map position ************\n" RST);
    while (current != NULL)
    {
        printf(O "Linha: %d, Coluna: %d, Conteúdo: %c up: %p down: %p\n" RST, current->line, current->column, current->content, current->up, current->down);
        current = current->nxt;
    }
    return 0;
}


int	parsing(t_game *data, char **argv)
{
    if (parse_file(argv[1], true) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++++    File  parsed    ++++++++\n" RST); // Retirar
	if (parse_data(argv[1], data) != 0)
		return (ERROR);
	if (DEBUG == 1)
	{
		printf(RED "\n++++++++    Data  parsed    ++++++++\n" RST); // Retirar
		if (DEBUGHARD == 1)
			print_map(data); // retirar
	}
	if (get_map_elements(data, data->mapinfo.file) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++++ Map elements parsed +++++++\n" RST); // Retirar
	if (parse_map(data, data->map) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n+++++++++    Map parsed    +++++++++\n" RST); // Retirar
	if (get_map_list_node(data, data->map) != 0)
		return (ERROR);
	if (DEBUG == 1)
	{
		printf(RED "\n+++++++++   List  filled   +++++++++\n" RST); // Retirar
		if (DEBUGHARD == 1)
			print_map_position(data); // Retirar
	}
	if (parse_textures(&data->texinfo) != 0)
		return (ERROR);
	if (DEBUG == 1)
		printf(RED "\n++++++    Textures  parsed    ++++++\n" RST); // Retirar
	return (SUCCESS);
}