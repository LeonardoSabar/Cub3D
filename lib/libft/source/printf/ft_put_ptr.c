/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:58:39 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:01:23 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

int	ft_put_ptr(unsigned long long pointer, int prefix)
{
	int			count;

	count = 0;
	if (!pointer)
	{
		count += ft_putstr_fd(NULL_PTR, ON);
		return (count);
	}
	if (prefix)
		count += ft_putstr_fd("0x", ON);
	if (pointer >= BASE_HEXA)
		count += ft_put_ptr(pointer / BASE_HEXA, OFF);
	count += ft_putchar_fd(HEXAMIN[pointer % BASE_HEXA], ON);
	return (count);
}
