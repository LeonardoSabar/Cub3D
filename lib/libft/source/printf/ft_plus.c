/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:22 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:01:06 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

int	ft_plus(const char *format, va_list ap)
{
	long long int	value;

	while (*format == '+')
		format++;
	if (*format == 'd' || *format == 'i')
	{
		value = (t_lolo)va_arg(ap, int);
		if (value >= 0)
			return (ft_putchar_fd('+', 1) + ft_putnbr_hex
				(value, BASE_DEC));
		return (ft_putnbr_hex(value, BASE_DEC));
	}
	return (0);
}
