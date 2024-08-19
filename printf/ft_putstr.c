/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:50:59 by smishos           #+#    #+#             */
/*   Updated: 2024/06/07 18:41:13 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	result;
	int	temp;

	result = 0;
	if (!str)
	{
		temp = ft_putstr("(null)");
		if (temp == -1)
			return (-1);
		result += temp;
	}
	else
	{
		while (*str)
		{
			temp = ft_putchar(*str);
			if (temp == -1)
				return (-1);
			result += temp;
			str++;
		}
	}
	return (result);
}
