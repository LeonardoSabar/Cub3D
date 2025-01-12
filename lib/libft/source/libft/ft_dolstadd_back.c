/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:43:35 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:43:47 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dolstadd_back(t_dolist **lst, t_element *new)
{
	t_element	*aux;

	aux = (*lst)->first;
	if (aux == NULL)
	{
		(*lst)->first = new;
		return ;
	}
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	new->prev = aux;
	(*lst)->size++;
	(*lst)->last = new;
}

