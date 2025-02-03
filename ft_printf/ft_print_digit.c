/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:31 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/21 13:48:04 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long n, int base)
{
	int		count;
	char	*ft_base;

	count = 0;
	ft_base = "0123456789abcdef";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += ft_print_digit(n / base, base);
	count += ft_print_char(ft_base[n % base]);
	return (count);
}
