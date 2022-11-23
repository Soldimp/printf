/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nugarcia < nugarcia@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:22 by nugarcia          #+#    #+#             */
/*   Updated: 2022/11/23 10:57:54 by nugarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(const char *s, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_unsigputnbr(unsigned int nbu, int *len);
void	ft_hexa(unsigned int nbr, char cs, int *len);
void	ft_print_memory(const void *ptr, int *len);

#endif
