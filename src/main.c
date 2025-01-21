/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:53:21 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/21 14:52:06 by leobarbo         ###   ########.fr       */
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
	return (0);
}
