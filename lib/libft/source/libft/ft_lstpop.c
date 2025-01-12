/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:50:55 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:50:57 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_el_is_first(t_dolist *lst, t_element *el)
{
	lst->first = el->next;
	if (lst->first)
		lst->first->prev = NULL;
}

static void	ft_el_is_last(t_dolist *lst, t_element *el)
{
	lst->last = el->prev;
	if (lst->last)
		lst->last->next = NULL;
}

t_element	*ft_lstpop(t_dolist *lst, int index)
{
	t_element	*el;

	el = ft_lstpickel(lst, index);
	if (!el)
		return (NULL);
	if (el != lst->first && el != lst->last)
	{
		el->prev->next = el->next;
		el->next->prev = el->prev;
	}
	else
	{
		if (el == lst->first)
			ft_el_is_first(lst, el);
		if (el == lst->last)
			ft_el_is_last(lst, el);
	}
	el->next = NULL;
	el->prev = NULL;
	lst->size--;
	return (el);
}
