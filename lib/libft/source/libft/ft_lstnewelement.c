/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewelement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:50:43 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:50:45 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lstnewelement(void *content)
{
	t_element	*el;

	el = ft_calloc(1, sizeof(t_element));
	if (el == NULL)
		return (NULL);
	el->content = content;
	return (el);
}
