/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:46:16 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:46:23 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_after(t_dolist *lst, t_element *ref, t_element *el)
{
	if (!el)
		return ;
	if (lst->last == ref)
		lst->last = el;
	el->next = ref->next;
	if (el->next)
		el->next->prev = el;
	ref->next = el;
	el->prev = ref;
	lst->size++;
}