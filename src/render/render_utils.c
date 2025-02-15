/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:22:25 by tsantana          #+#    #+#             */
/*   Updated: 2025/02/10 17:44:15 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	nor_angle(float angle)
{
	float	pi_2;
	
	pi_2 = M_PI * 2;
	return (pi_2 - (pi_2 * ((int)(angle / pi_2))));
}

float	pytheorem(float a, float b)
{
	return (sqrt((a * a) + (b * b)));
}

int	h_unit_circle(float angle)
{
	return (angle > 0 && angle < M_PI);
}

int	v_unit_circle(float angle)
{
	return (angle > M_PI * 0.5 && angle < M_PI * 1.5);
}

uint32_t	reverse_bytes(unsigned int c)
{
	return ((c & R) >> 8 | (c & G) << 8 | (c & B) << 24 | (c & A) >> 24);
}

// mlx_texture_t	*get_texture(t_game *gm)
// {
// 	gm->ray.ray_ngl = nor_angle(gm->ray.ray_ngl);
// 	if (gm->texinfo.y)
// 	{
// 		if (vertical_unit_circle(gm->ray.ray_ngl))
// 			return (gm->texinfo.west);
// 		return (gm->texinfo.east);
// 	}
// 	if (horizontal_unit_circle(gm->ray.ray_ngl))
// 		return (gm->texinfo.south);
// 	return (gm->texinfo.north);
// }

// int	h_unit_circle(float angle)
// {
// 	return (angle > 0 && angle < M_PI);
// }

// int	v_unit_circle(float angle)
// {
// 	return (angle > M_PI * 0.5 && angle < M_PI * 1.5);
// }