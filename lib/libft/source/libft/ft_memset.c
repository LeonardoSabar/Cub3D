/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:54:03 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:42:11 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		((char *)s)[idx] = (char)c;
		idx++;
	}
	return (s);
}
