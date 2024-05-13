/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:45 by mgreshne          #+#    #+#             */
/*   Updated: 2024/03/10 21:59:52 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_symbol(va_list ap, char *str)
{
	if (*str == '%')
		return (ft_print_char(*str));
	else if (*str == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (*str == 's')
		return (ft_print_string(va_arg(ap, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_print_int(va_arg(ap, int)));
	else if (*str == 'p')
		return (ft_print_p(va_arg(ap, void *)));
	else if (*str == 'x' || *str == 'X' )
	{
		if (*str == 'x')
			return (ft_transform_print(va_arg(ap, unsigned int), HEXI_LOW));
		else
			return (ft_transform_print(va_arg(ap, unsigned int), HEXI_UP));
	}
	else if (*str == 'u')
		return (ft_print_unsigned_int(va_arg(ap, unsigned int)));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		count;

	if (!string)
		return (0);
	count = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			count += check_symbol(ap, (char *)string);
		}
		else
			count += ft_print_char(*string);
		string++;
	}
	va_end(ap);
	return (count);
}
