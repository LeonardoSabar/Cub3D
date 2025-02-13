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
	
	intro();
	if(argc != 2)
		return (err_msg("Invalid number of arguments!", 1));
	init_data(&data);
	if (parsing(&data, argv) == ERROR)
		clean_exit(&data, 1);

	data.mlx_on = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!data.mlx_on)
		printf("Error: %s\n", mlx_strerror(mlx_errno));
	data.bg_img = mlx_new_image(data.mlx_on, WIDTH, HEIGHT);
	if (!data.bg_img)
		return (clean_exit(&data, 1), 1);
	mlx_loop_hook(data.mlx_on, &game_loop2, &data);
	mlx_key_hook(data.mlx_on, &mlx_key, &data);

	printf("width: %d, height: %d\n", data.mapinfo.width, data.mapinfo.height);
	mlx_loop(data.mlx_on);
	mlx_terminate(data.mlx_on);
	clean_exit(&data, 0);
	return 0;
}
