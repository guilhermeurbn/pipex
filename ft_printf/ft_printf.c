/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhermeurbano <guilhermeurbano@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:15:27 by guilhermeur       #+#    #+#             */
/*   Updated: 2024/11/22 10:26:10 by guilhermeur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char special, va_list *args)
{
	int	count;

	count = 0;
	if (special == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (special == 's')
		count += ft_print_str(va_arg(*args, char *));
	else if (special == 'p')
		count += ft_print_pointer((unsigned long)va_arg(*args, void *));
	else if (special == 'd' || special == 'i')
		count += ft_print_digit((long)(va_arg(*args, int)), 10);
	else if (special == 'u')
		count += ft_print_digit_n_negative((va_arg(*args, unsigned int)), 10);
	else if (special == 'x')
		count += ft_print_digit((long)(va_arg(*args, unsigned int)), 16);
	else if (special == 'X')
		count += ft_print_digit_upper((long)(va_arg(*args, unsigned int)), 16);
	else if (special == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(special);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	va_start (args, format);
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_print_format(format[i], &args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end (args);
	return (count);
}
/* int main()
{
	char *a;
	char *b = "hello world!";
	a = b;

 	//%c Imprime um único caractere.
	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');
	printf("\n");


	//%s Imprime uma string
	ft_printf("Hello, %s!\n", "World");
	printf("Hello, %s!\n", "World");
	printf("\n");

	//%p O endereço do ponteiro void *
	//deve ser impresso em formato hexadecimal.
	ft_printf("endereco: %p\n", a);
	printf("endereco: %p\n", a);
	printf("\n");


	//%d Imprime um número decimal (base 10).
	ft_printf("Decimal: %d\n", 42);
	printf("Decimal: %d\n", 42);
	printf("\n");

	//%i Imprime um inteiro em base 10.
	ft_printf("Decimal base 10: %i\n", 42);
	printf("Decimal base 10: %i\n", 42);
	printf("\n");

	//%u Imprime um número decimal (base 10) sem sinal.
	ft_printf("Decimal sem sinal: %u\n", 42);
	printf("Decimal sem sinal: %u\n", 42);
	printf("\n");

	//%x Imprime um número em formato hexadecimal (base 16) em minúsculas.
	ft_printf("Hexadecimal (minusculas): %x\n", 600);
	printf("Hexadecimal (minusculas): %x\n", 600);
	printf("\n");

	//%X Imprime um número em formato hexadecimal (base 16) em maiúsculas.
	ft_printf("Hexadecimal (maisculas): %X\n", 42);
	printf("Hexadecimal (maisculas): %X\n", 42);
	printf("\n");

	//%% Imprime um sinal de porcentagem
	ft_printf("sinal de porcentagem: %%\n");
	printf("sinal de porcentagem: %%\n");
	printf("\n");

} */
/*
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define FAIL "***************** TEST FAILED **********************\n\n"

int	main(void)
{
	int a;
	int b;

	// x tests
	printf("x tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%x", 0));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 0));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", -1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", -1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", 1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", 10));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 10));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", 99));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", 99));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", -101));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x", -101));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%x %x %x %x", INT_MAX,
			INT_MIN, 0, -42));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%x %x %x %x",
			INT_MAX, INT_MIN, 0, -42));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// X tests
	printf("X tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%X", 0));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 0));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", -1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", -1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", 1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", 10));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 10));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", 99));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", 99));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", -101));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X", -101));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%X %X %X %X", INT_MAX,
			INT_MIN, 0, -42));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%X %X %X %X",
			INT_MAX, INT_MIN, 0, -42));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// c tests
	printf("c tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%c", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%c ", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c ", '0'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c ", '0'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c", '0' - 256));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c", '0'
			- 256));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%c ", '0' + 256));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'
			+ 256));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c %c %c ", '1', '2',
			'3'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c %c %c ",
			'1', '2', '3'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf("%c ", '0' + 256));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%c ", '0'
			+ 256));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %c %c %c ", '1', '2',
			'3'));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %c %c %c ",
			'1', '2', '3'));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// d & i tests
	printf("d & i tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %d ", -99));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ", -99));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", 100));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ", 100));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %d ", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %d ",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// p tests
	printf("p tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)-1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)-1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)1));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)1));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)15));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)15));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p ", (void *)0));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			(void *)0));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf("p tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %p ", NULL));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p ",
			NULL));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
			(void *)LONG_MIN, (void *)LONG_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
			(void *)LONG_MIN, (void *)LONG_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
			(void *)INT_MIN, (void *)INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
			(void *)INT_MIN, (void *)INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %p %p ",
			(void *)ULONG_MAX, (void *)-ULONG_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %p %p ",
			(void *)ULONG_MAX, (void *)-ULONG_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// s tests

	char *s = "this is a longer test string to test printf";

	printf("s tests\n");
	printf(" printf out\n%d printf length\n", a = printf("%s", ""));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf("%s", ""));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %s %s ", "", "-"));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %s %s ", "",
			"-"));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	// u tests
	printf("u tests\n");
	printf(" printf out\n%d printf length\n", a = printf(" %u ", -100));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			-100));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %u ", INT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			INT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %u ", INT_MIN));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			INT_MIN));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

	printf(" printf out\n%d printf length\n", a = printf(" %u ", UINT_MAX));
	printf(" ft_printf out\n%d ft_printf length\n", b = ft_printf(" %u ",
			UINT_MAX));
	a == b ? printf("TEST PASSED\n\n") : printf(FAIL);

} */
