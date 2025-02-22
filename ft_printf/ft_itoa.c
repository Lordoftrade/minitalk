/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:44 by mgreshne          #+#    #+#             */
/*   Updated: 2024/02/13 19:03:44 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(int nbr)
{
	int	len;

	len = (nbr <= 0);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*ft_from_nbr_to_str(char *str, int n, int len)
{
	long long	nbr;

	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[len] = '\0';
	len--;
	while (nbr)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = nbr_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[len--] = '\0';
		str[len] = '0';
	}
	else
		ft_from_nbr_to_str(str, n, len);
	return (str);
}
