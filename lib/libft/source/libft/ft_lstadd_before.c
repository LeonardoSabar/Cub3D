/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:47:35 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:47:42 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_before(t_dolist *lst, t_element *ref, t_element *el)
{
	if (!el)
		return ;
	if (lst->first == ref)
		lst->first = el;
	el->prev = ref->prev;
	if (el->prev)
		el->prev->next = el;
	ref->prev = el;
	el->next = ref;
	lst->size++;
}