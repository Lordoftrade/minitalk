/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgreshne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:54 by mgreshne          #+#    #+#             */
/*   Updated: 2024/04/14 17:11:10 by mgreshne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>

# define HEXI_LOW "0123456789abcdef"
# define HEXI_UP "0123456789ABCDEF"
# define DEC_BASE "0123456789"

int		ft_printf(const char *string, ...);

char	*ft_itoa(int n);
int		ft_print_int(int i);
int		ft_print_char(char c);
int		ft_print_string(char *str);
size_t	ft_strlen(const char *s);
int		ft_print_p(void *ptr);
int		ft_print_unsigned_int(unsigned long value);
int		ft_transform_print(unsigned long long n, const char *base);

#endif
