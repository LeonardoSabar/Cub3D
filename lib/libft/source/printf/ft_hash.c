/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:08 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:00:58 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

int	ft_hash(const char *format, va_list ap)
{
	long long int	value;

	value = (t_lolo)va_arg(ap, t_uni);
	if (value == 0)
		return (ft_putstr_fd("0", 1));
	if (*format == 'x')
		return (ft_putstr_fd("0x", 1) + ft_putnbr_hex(value, HEXAMIN));
	else if (*format == 'X')
		return (ft_putstr_fd("0X", 1) + ft_putnbr_hex(value, HEXAMAX));
	return (0);
}
