/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_n_negative.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:28 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/21 13:43:47 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_n_negative(long n, int base)
{
	int		count;
	char	*ft_base;

	count = 0;
	ft_base = "0123456789abcdef";
	if (n >= base)
		count += ft_print_digit_n_negative(n / base, base);
	count += ft_print_char(ft_base[n % base]);
	return (count);
}
