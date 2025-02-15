/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:13:24 by leobarbo          #+#    #+#             */
/*   Updated: 2025/02/15 20:40:35 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == KEY_ESC && keydata.action == KEY_PRESS)
		clean_exit(data, 0); // Tratar o caso de apertar ESC
	if (keydata.key == KEY_W && keydata.action == KEY_PRESS)
		data->key_data.w = true;
	if (keydata.key == KEY_S && keydata.action == KEY_PRESS)
		data->key_data.s = true;
	if (keydata.key == KEY_A && keydata.action == KEY_PRESS)
		data->key_data.a = true;
	if (keydata.key == KEY_D && keydata.action == KEY_PRESS)
		data->key_data.d = true;

}
