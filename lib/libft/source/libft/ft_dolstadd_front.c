/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:44:17 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:44:28 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dolstadd_front(t_dolist **lst, t_element *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst)->first;
	new->prev = NULL;
	(*lst)->first->prev = new;
	(*lst)->first = new;
	(*lst)->size++;
}