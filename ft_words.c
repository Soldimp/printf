/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:58 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/23 10:58:18 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

void	ft_putstr(const char *s, int *len)
{
	unsigned int	i;

	if (!s)
		ft_putstr("(null)", len);
	else
	{
		i = 0;
		while (s[i] != '\0')
			ft_putchar(s[i++], len);
	}
}
