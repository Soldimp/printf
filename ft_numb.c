/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:21 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/21 11:34:56 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr *= -1;
		ft_putnbr(nbr, len);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
		ft_putchar(nbr + 48, len);
}

/*void	ft_unsigned_nbr(unsigned int n, int *len)
{
	if (n >= 10)
		ft_unsigned_nbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}*/

void	ft_unsigputnbr(unsigned int nb, int *index)
{
	if (nb > 9)
	{
		ft_unsigputnbr(nb / 10, index);
		ft_unsigputnbr(nb % 10, index);
	}
	else
		ft_putchar(nb + 48, index);
}

void	ft_hexa(unsigned int nbr, char cs, int *len)
{
	char	*base;

	if (cs == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(base[nbr % 16], len);
	else
	{
		ft_hexa((nbr / 16), cs, len);
		ft_hexa((nbr % 16), cs, len);
	}
}

// Similar to ft_putnbr_base
static void	ft_puthex(unsigned long int nb, int *index)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(base[nb % 16], index);
	else
	{
		ft_puthex(nb / 16, index);
		ft_puthex(nb % 16, index);
	}
}

// Prints memory address to the std output
void	ft_print_memory(const void *ptr, int *index)
{
	unsigned long int	address;

	address = (unsigned long int)ptr;
	if (address == 0)
	{
		*index += write (1, "(nil)", 5);
		return ;
	}
	ft_putstr("0x", index);
	ft_puthex(address, index);
}
