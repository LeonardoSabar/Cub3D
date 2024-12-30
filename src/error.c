/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:55:46 by leobarbo          #+#    #+#             */
/*   Updated: 2024/12/30 17:35:17 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	err_msg(char *message, int code)
{
	ft_putstr_fd(RED "Cub3D Error" RST, 2);
	if (message)
	{
		ft_putstr_fd(Y ": ", 2);
		ft_putstr_fd(message, 2);
	}
	ft_putstr_fd("!\n" RST, 2); //CONFIRMAR SE É 2(RESET)
	return (code);
}
