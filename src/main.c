/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:07:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/09/28 10:33:27 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parsing(t_data *data, char **argv)
{
    if (parse_file(argv[1]) == 1)
        clean_exit(data, 1); 
    parse_data(argv[1], data);
	if (get_file_data(data, data->mapinfo.file) == 1)
		return (free_data(data));
	// parse_args();
	// parse_textures();
	// parse_sprites();
	// parse_colors();
}
int	main(int argc, char **argv)
{
	t_game	data;
	
    if(argc != 2)
        return (err_msg("Invalid number of arguments", 1));
    init_data(&data);
    parsing(&data, argv);


	// init();
	// render();
	// game_loop();
	// free();
}
