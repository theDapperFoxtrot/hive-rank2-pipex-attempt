/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:10:00 by smishos           #+#    #+#             */
/*   Updated: 2024/06/10 13:34:12 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	result;
	int	temp;

	result = 0;
	if (n >= 10)
	{
		temp = ft_putunbr(n / 10);
		if (temp == -1)
			return (-1);
		result += temp;
	}
	temp = ft_putchar(n % 10 + '0');
	if (temp == -1)
		return (-1);
	result += temp;
	return (result);
}
