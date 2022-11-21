/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:07:58 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/21 12:18:37 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *index)
{
	write (1, &c, 1);
	(*index)++;
}

void	ft_putstr(const char *s, int *index)
{
	unsigned int	i;

	if (!s)
		ft_putstr("(null)", index);
	else
	{
		i = 0;
		while (s[i] != '\0')
			ft_putchar(s[i++], index);
	}
}
