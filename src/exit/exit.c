/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:38:32 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/15 01:31:51 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void clean_exit(t_game *data, int code)
{
    //free_resources(data);
    if (data->mlx_on)
    {
        /*
        if (data->img)
            mlx_delete_image(data->mlx_on, data->img);
        if (data->game)
            mlx_delete_image(data->mlx_on, data->game);
        if (data->p_img)
            mlx_delete_image(data->mlx_on, data->p_img);
        if (data->bg_img)
            mlx_delete_image(data->mlx_on, data->bg_img);
        mlx_terminate(data->mlx_on);
    */
    }
    printf(RED "Falta implementar a liberação de recursos" RST "\n"); // Retirar
    ft_printf(RED "Resources freed. Exiting with code %d." RST "\n", code);
    exit(code);
}
