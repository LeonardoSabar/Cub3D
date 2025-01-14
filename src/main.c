/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:07:02 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/14 00:26:37 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int print_map(t_game *data)
{
    // Verificar se mapinfo e file estão definidos
	if (data == NULL || data->mapinfo.file == NULL)
    {
        return -1; // Falha ao imprimir, estrutura inválida
    }

	for (int i = 0; i < data->mapinfo.line_count; i++) // itera o número de linhas
    {
		if (data->mapinfo.file[i] != NULL) // Verifica se a linha não é NULL
        {
			printf("%s\n", data->mapinfo.file[i]); // Imprime a linha do conteúdo do mapa
		  }
    }
    return 0;
}
  

static int	parsing(t_game *data, char **argv)
{
    if (parse_file(argv[1]) != 0)
		return (ERROR);
	printf(RED "File parsed\n" RST); // Retirar
	if (parse_data(argv[1], data) != 0)
		return (ERROR);
	printf(RED "Data parsed\n" RST); // Retirar
	print_map(data); // retirar
	if (get_file_data(data, data->mapinfo.file) == 1)
		return (ERROR);
	printf(RED "File data parsed\n" RST); // Retirar
	if (parse_map(data, data->map) != 0)
	// parse_textures();
	// parse_sprites();
	// parse_colors();
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	data;

    if(argc != 2)
        return (err_msg("Invalid number of arguments!", 1));
    init_data(&data);
    if (parsing(&data, argv) != 0)
		clean_exit(&data, 1);



	// init();
	// render();
	// game_loop();
	// free();
}
