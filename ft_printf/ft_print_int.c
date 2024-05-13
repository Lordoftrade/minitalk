/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:11 by mgreshne          #+#    #+#             */
/*   Updated: 2024/02/13 19:04:11 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int i)
{
	char	*str;
	int		len;

	if (!i || i == 0)
		return (ft_print_char('0'));
	str = ft_itoa(i);
	if (!str)
	{
		free(str);
		return (-1);
	}
	len = ft_print_string(str);
	free(str);
	return (len);
}
