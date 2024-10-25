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

int	main(int argc, char **argv)
{
	cub3d_t	game;
	if (argc != 2)
		return (1); //Retornar mensagem de erro personalizada aqui.

	game.mlx = mlx_init();
	// parsing();
	// init();
	// render();
	// game_loop();
	// free();
}
