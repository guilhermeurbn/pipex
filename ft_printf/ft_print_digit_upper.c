/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:18 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/21 13:21:51 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_upper(long n, int base)
{
	int		count;
	char	*ft_base;

	count = 0;
	ft_base = "0123456789ABCDEF";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		count += ft_print_digit_upper(n / base, base);
	count += ft_print_char(ft_base[n % base]);
	return (count);
}
