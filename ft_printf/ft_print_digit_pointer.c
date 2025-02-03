/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhermeurbano <guilhermeurbano@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:16 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/22 10:29:34 by guilhermeur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_pointer(unsigned long n, unsigned long base)
{
	int		count;
	char	*ft_base;

	if (base < 2 || base > 16)
    	return (0);
	count = 0;
	ft_base = "0123456789abcdef";
	if (n >= base)
		count += ft_print_digit_pointer(n / base, base);
	count += ft_print_char(ft_base[n % base]);
	return (count);
}
