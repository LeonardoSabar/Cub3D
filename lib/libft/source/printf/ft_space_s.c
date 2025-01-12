/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:58:46 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 15:01:29 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

int	ft_space_s(const char *format, va_list ap)
{
	int		numb;
	int		count;
	char	*value_string;

	numb = ft_atoi(format);
	count = 0;
	while (ft_isdigit(*format))
		format++;
	if (*format == 's')
	{
		if (numb > 0)
		{
			while (numb--)
				count += ft_putchar_fd(' ', 1);
		}
		value_string = va_arg(ap, char *);
		if (value_string == NULL)
			return (ft_putstr_fd(NULL_STR, 1) + count);
		return (ft_putstr_fd(value_string, 1) + count);
	}
	return (count);
}
