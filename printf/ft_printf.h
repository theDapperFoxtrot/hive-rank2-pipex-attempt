/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:35:21 by smishos           #+#    #+#             */
/*   Updated: 2024/06/10 13:33:10 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned long nbr, const char format, int is_pointer);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str);
int	ft_putunbr(unsigned int n);

#endif

//I need to address when the putchar() function returns -1:
