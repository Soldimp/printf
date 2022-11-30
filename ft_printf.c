/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:41:55 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/30 15:28:28 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	ft_check_printdata(va_list arg, const char str, int *len)
{
	if (str == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (str == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (str == 'p')
		ft_print_memory(va_arg(arg, unsigned long int), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (str == 'u')
		ft_unsigputnbr(va_arg(arg, unsigned int), len);
	else if (str == 'x')
		ft_hexa(va_arg(arg, unsigned int), str, len);
	else if (str == 'X')
		ft_hexa(va_arg(arg, unsigned int), str, len);
	else if (str == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_check_printdata(arg, *str, &len);
		}
		else
			ft_putchar(*str, &len);
		str++;
	}
	va_end(arg);
	return (len);
}

/* int main()
{
    system("clear");
    char chr = 'D';
    char chr2 = 'o';
    char chr3 = 'B';
    char num = '0';
    char num2 = '1';
    char num3 = '3';
    char num4 = '0';
    int numero_pos = 13;
    int numero_neg = -13;
    char *short_string = "42 Lisboa";
    char *long_string = "Eu sou um aluno da 42 Lisboa!";
    int text_fake;
    int text_original;
    int hex_number_pos = 1;
    int hex_number_neg = -1;
    char *addr_null = NULL;
    
    printf("\n-------- ORIGINAL --------\n");
    text_original = printf("hello World\n");
    printf("%d\n", text_original);
    text_original = printf("Escapes -> \\\\\\");
    printf("\n");
    printf("%d\n", text_original);
    //%c
    text_original = printf("Texto -> %ci%cgo\nTexto -> %cea\n", chr, chr2, chr3);
    printf("%d\n", text_original);
    text_original = printf("Char Num -> %c%c%c%c\n", num, num2, num3, num4);
    printf("%d\n", text_original);
    //%%
    text_original = printf("%% Char -> %%%%\n");
    printf("%d\n", text_original);
    //%d and %i
    text_original = printf("Numero Inteiro (+) ->  %i\n", numero_pos);
    printf("%d\n", text_original);
    text_original = printf("Numero Inteiro (-) -> %d\n", numero_neg);
    printf("%d\n", text_original);
    //%u
    text_original = printf("Numero Inteiro Unsigned (+) -> %u\n", numero_pos);
    printf("%d\n", text_original);
    text_original = printf("Numero Inteiro Unsigned (-) -> %u\n", numero_neg);
    printf("%d\n", text_original);
    //%s
    text_original = printf("Short String -> %s\n", short_string);
    printf("%d\n", text_original);
    text_original = printf("Long String  -> %s\n", long_string);
    printf("%d\n", text_original);
    //%x
    text_original = printf("Hex Number (Lower) (+) -> %x\n", hex_number_pos);
    printf("%d\n", text_original);
    text_original = printf("Hex Number (Lower) (-) -> %x\n", hex_number_neg);
    printf("%d\n", text_original);
    //%X
    text_original = printf("Hex Number (Upper) (+) -> %X\n", hex_number_pos);
    printf("%d\n", text_original);
    text_original = printf("Hex Number (Upper) (-) -> %X\n", hex_number_neg);
    printf("%d\n", text_original);
    //%p
    text_original = printf("Addres Pointer -> %p\n", LONG_MIN);
    printf("%d\n", text_original);
    text_original = printf("Addres Pointer (Null) -> %p\n", addr_null);
    printf("%d\n", text_original);
    text_original = printf("--------------------------\n");
    
    printf("---------- FAKE ----------\n");
    text_fake = ft_printf("hello World\n");
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Escapes -> \\\\\\");
    ft_printf("\n");
    ft_printf("%d\n", text_fake);
    //%c
    text_fake = ft_printf("Texto -> %ci%cgo\nTexto -> %cea\n", chr, chr2, chr3);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Char Num -> %c%c%c%c\n", num, num2, num3, num4);
    ft_printf("%d\n", text_fake);
    //%%
    text_fake = ft_printf("%% Char -> %%%%\n");
    ft_printf("%d\n", text_fake);
    //%d and %i
    text_fake = ft_printf("Numero Inteiro (+) ->  %i\n", numero_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Numero Inteiro (-) -> %d\n", numero_neg);
    ft_printf("%d\n", text_fake);
    //%u
    text_fake = ft_printf("Numero Inteiro Unsigned (+) -> %u\n", numero_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Numero Inteiro Unsigned (-) -> %u\n", numero_neg);
    ft_printf("%d\n", text_fake);
    //%s
    text_fake = ft_printf("Short String -> %s\n", short_string);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Long String  -> %s\n", long_string);
    ft_printf("%d\n", text_fake);
    //%x
    text_fake = ft_printf("Hex Number (Lower) (+) -> %x\n", hex_number_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Hex Number (Lower) (-) -> %x\n", hex_number_neg);
    ft_printf("%d\n", text_fake);
    //%X
    text_fake = ft_printf("Hex Number (Upper) (+) -> %X\n", hex_number_pos);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Hex Number (Upper) (-) -> %X\n", hex_number_neg);
    ft_printf("%d\n", text_fake);
    //%p
    text_fake = ft_printf("Addres Pointer -> %p\n", LONG_MIN);
    ft_printf("%d\n", text_fake);
    text_fake = ft_printf("Addres Pointer (Null) -> %p\n", addr_null);
    ft_printf("%d\n", text_fake);
	printf("--------------------------\n");   
} */