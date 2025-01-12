/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:42:31 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:06:24 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	slen;

	slen = ft_strlen(src);
	if (size != 0)
	{
		while (*src && --size)
		{
			*dest = *src;
			src++;
			dest++;
		}
	*dest = '\0';
	}
	return (slen);
}
