/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:23 by mgreshne          #+#    #+#             */
/*   Updated: 2024/02/13 19:04:23 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	count;

	count = 0;
	if (str != NULL)
	{
		while (*str)
			count += ft_print_char(*str++);
		return (count);
	}
	else
		return (ft_print_string("(null)"));
}
