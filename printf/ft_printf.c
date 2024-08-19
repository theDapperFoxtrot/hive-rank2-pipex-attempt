/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:34:34 by smishos           #+#    #+#             */
/*   Updated: 2024/06/10 13:33:45 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char format, va_list *ap)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_putchar(va_arg(*ap, int));
	else if (format == 's')
		result = ft_putstr(va_arg(*ap, char *));
	else if (format == 'p')
		result = ft_putptr(va_arg(*ap, void *));
	else if (format == 'd' || format == 'i')
		result = ft_putnbr(va_arg(*ap, int));
	else if (format == 'u')
		result = ft_putunbr(va_arg(*ap, unsigned int));
	else if (format == 'x')
		result = ft_puthex(va_arg(*ap, unsigned int), 'x', 0);
	else if (format == 'X')
		result = ft_puthex(va_arg(*ap, unsigned int), 'X', 0);
	else if (format == '%')
		result = ft_putchar('%');
	return (result);
}

int	accumulate_length(size_t *total_len, int len)
{
	if (len == -1)
		return (-1);
	*total_len += len;
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	total_len;
	int		len;

	total_len = 0;
	va_start(ap, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 0)
				break ;
			len = handle_format(*input, &ap);
		}
		else
			len = ft_putchar(*input);
		if (accumulate_length(&total_len, len) == -1)
			return (-1);
		input++;
	}
	va_end(ap);
	return (total_len);
}
