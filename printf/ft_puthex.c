/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:04:40 by smishos           #+#    #+#             */
/*   Updated: 2024/06/10 13:33:51 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlen(unsigned long n, int is_pointer)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	if (is_pointer)
		len += 2;
	return (len);
}

static char	*format_check(const char format)
{
	if (format == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int	ft_puthex(unsigned long nbr, const char format, int is_pointer)
{
	char			*hex;
	int long long	digit;
	int				shift;
	int				zero_check;

	hex = format_check(format);
	shift = (sizeof(nbr) * 8) - 4;
	zero_check = 1;
	while (shift >= 0)
	{
		digit = (nbr >> shift) & 0xf;
		if (digit != 0 || !zero_check)
		{
			if (ft_putchar(hex[digit]) == -1)
				return (-1);
			zero_check = 0;
		}
		shift -= 4;
	}
	if (zero_check)
		if (ft_putchar('0') == -1)
			return (-1);
	return (hexlen(nbr, is_pointer));
}
