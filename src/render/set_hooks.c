/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:33:43 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/16 05:33:46 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	release_key(t_game *data, int key)
{
	if (key == MLX_KEY_W)
		data->key_data.w = false;
	else if (key == MLX_KEY_A)
		data->key_data.a = false;
	else if (key == MLX_KEY_S)
		data->key_data.s = false;
	else if (key == MLX_KEY_D)
		data->key_data.d = false;
	else if (key == MLX_KEY_LEFT)
		data->key_data.left = false;
	else if (key == MLX_KEY_RIGHT)
		data->key_data.right = false;
}

static void	press_key(t_game *data, int key)
{
	if (key == MLX_KEY_W)
		data->key_data.w = true;
	else if (key == MLX_KEY_A)
		data->key_data.a = true;
	else if (key == MLX_KEY_S)
		data->key_data.s = true;
	else if (key == MLX_KEY_D)
		data->key_data.d = true;
	else if (key == MLX_KEY_LEFT)
		data->key_data.left = true;
	else if (key == MLX_KEY_RIGHT)
		data->key_data.right = true;
}

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_exit(data, 0); // Tratar o caso de apertar ESC
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		press_key(data, keydata.key);
	else if (keydata.action == MLX_RELEASE)
		release_key(data, keydata.key);
}
