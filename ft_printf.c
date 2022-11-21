/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:41:55 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/21 12:33:04 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_printdata(va_list arg, const char str, int *len)
{
	if (str == 'c')
		ft_putchar((char)va_arg(arg, int), len);
	else if (str == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (str == 'p')
		ft_print_memory(va_arg(arg, void *), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (str == 'u')
		ft_unsigputnbr(va_arg(arg, unsigned int), len);
	else if (str == 'x')
		ft_hexa(va_arg(arg, int), str, len);
	else if (str == 'X')
		ft_hexa(va_arg(arg, int), str, len);
	else if (str == '%')
		ft_putchar('%', len);
	else
		ft_putchar((char)va_arg(arg, int), len);
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

int main()
{
	int a = 590;
	ft_printf(" %d %p ", a, 0);
}