/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:58:52 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:01:34 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

int	ft_space(const char *format, va_list ap)
{
	long long int	value;

	while (*format == ' ')
		format++;
	if (*format == 'd' || *format == 'i')
	{
		value = (t_lolo)va_arg(ap, int);
		if (value >= 0)
			return (ft_putchar_fd(' ', 1) + ft_putnbr_hex
				(value, BASE_DEC));
		return (ft_putnbr_hex(value, BASE_DEC));
	}
	if (*format == 's' || ft_isdigit(*format))
		return (ft_space_s(format, ap));
	return (0);
}
