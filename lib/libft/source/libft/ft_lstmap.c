/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:50:25 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 14:50:28 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	new_list = 0;
	while (lst)
	{
		tmp = f(lst -> content);
		new = ft_lstnew(tmp);
		if (!new)
		{
			ft_lstclear(&new_list, del);
			free (tmp);
			return (0);
		}
		ft_lstadd_back(&new_list, new);
		lst = lst -> next;
	}
	return (new_list);
}
