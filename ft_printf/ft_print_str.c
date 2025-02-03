/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:35:58 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/20 14:30:17 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		count += ft_print_char((int) str[i]);
		i++;
	}
	return (count);
}
