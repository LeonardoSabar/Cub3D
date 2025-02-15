/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:47:28 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/15 20:07:44 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_screen(t_game *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx_on = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!data->mlx_on)
		clean_exit(data, 1);
	data->img = mlx_new_image(data->mlx_on, WIDTH, HEIGHT);
	if (!data->img)
		clean_exit(data, 1);
	if (mlx_image_to_window(data->mlx_on, data->img, 0, 0) < 0)
		clean_exit(data, 1);
}
