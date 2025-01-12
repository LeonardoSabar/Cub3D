/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:02 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:00:53 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_flag_check(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == '#')
		count += ft_hash(++format, ap);
	else if (*format == '+')
		count += ft_plus(++format, ap);
	else if (*format == ' ')
		count += ft_space(++format, ap);
	return (count);
}
