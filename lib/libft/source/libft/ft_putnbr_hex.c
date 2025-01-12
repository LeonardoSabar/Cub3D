/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:03:41 by leobarbo          #+#    #+#             */
/*   Updated: 2025/01/12 17:03:50 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_hex(long long num, char *base)
{
	int			count;
	int			len_base;

	len_base = ft_strlen(base);
	count = 0;
	if (num < 0)
	{
		count += ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num >= len_base)
		count += ft_putnbr_hex(num / len_base, base);
	count += ft_putchar_fd(base[num % len_base], 1);
	return (count);
}