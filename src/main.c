/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:53:21 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/13 01:02:00 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	data;

	if(argc != 2)
		return (err_msg("Invalid number of arguments!", 1));
	init_data(&data);
	if (parsing(&data, argv) == ERROR)
		clean_exit(&data, 1);
	data.texinfo->tex = create_texture(&data);
	data.mlx_on = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	init_background(&data);
	mlx_loop_hook(data.mlx_on, &game_loop2, &data);
	mlx_key_hook(data.mlx_on, &mlx_key, &data);
	printf("width: %d, height: %d\n", data.mapinfo.width, data.mapinfo.height);
	mlx_loop(data.mlx_on);
	mlx_terminate(data.mlx_on);
	return (clean_exit(&data, 0), 0);
	return 0;
}
