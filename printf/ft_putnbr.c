/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:00:12 by smishos           #+#    #+#             */
/*   Updated: 2024/06/10 13:33:31 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_helper(int n)
{
	int	result;
	int	temp;

	result = 0;
	if (n >= 10)
	{
		temp = ft_putnbr_helper(n / 10);
		if (temp == -1)
			return (-1);
		result += temp;
	}
	temp = ft_putchar((n % 10) + '0');
	if (temp == -1)
		return (-1);
	result += temp;
	return (result);
}

int	ft_putnbr(int n)
{
	int	result;
	int	temp;

	result = 0;
	if (n == -2147483648)
	{
		temp = ft_putstr("-2147483648");
		if (temp == -1)
			return (-1);
		result += temp;
		return (result);
	}
	if (n < 0)
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		result += temp;
		n = -n;
	}
	temp = ft_putnbr_helper(n);
	if (temp == -1)
		return (-1);
	result += temp;
	return (result);
}
