/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:12:01 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/28 18:12:01 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_print_ptr(char *digits, int *pos)
{
	int		c;
	int		len;

	ft_putstr_fd("0x", 1);
	len = 2;
	c = 15;
	while (c >= 0)
	{
		if (digits[c] != 'x')
		{
			ft_putchar_fd(digits[c], 1);
			len++;
		}
		c--;
	}
	pos[1] += len;
}

void	ft_percent_p(unsigned long long int n, int *pos)
{
	int		c;
	char	digits[16];
	char	*hex_table;

	hex_table = "0123456789abcdef";
	c = 0;
	while (c <= 15)
	{
		if (c > 0 && n == 0)
			digits[c] = 'x';
		else
			digits[c] = hex_table[n % 16];
		n /= 16;
		c++;
	}
	ft_print_ptr(digits, pos);
}
