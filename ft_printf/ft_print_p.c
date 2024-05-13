/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:18 by mgreshne          #+#    #+#             */
/*   Updated: 2024/02/13 19:04:18 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *ptr)
{
	int				count;
	unsigned long	adress;

	count = 0;
	adress = (unsigned long)ptr;
	count += ft_print_string("0x");
	count += ft_transform_print(adress, HEXI_LOW);
	return (count);
}
