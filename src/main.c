/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:07:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/27 16:30:19 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	parsing(t_game *data, char **argv)
{
    if (parse_file(argv[1]) == 1)
		return (ERROR);
        // clean_exit(data, 1); Fix clean_exit
	if (parse_data(argv[1], data) == 1)
		return (ERROR);
	if (get_file_data(data, data->mapinfo.file) == 1)
		return (ERROR);
		//return (free_data(data));
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
		return (1);


	// init();
	// render();
	// game_loop();
	// free();
}
