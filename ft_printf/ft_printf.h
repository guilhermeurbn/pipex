/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:15:32 by guisanto          #+#    #+#             */
/*   Updated: 2024/11/21 13:48:37 by guisanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_str(char *str);
int	ft_print_digit(long n, int base);
int	ft_print_char(int c);
int	ft_print_digit_n_negative(long n, int base);
int	ft_print_digit_upper(long n, int base);
int	ft_print_pointer(unsigned long b);
int	ft_print_digit_pointer(unsigned long n, unsigned long base);

#endif
