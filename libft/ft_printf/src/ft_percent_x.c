/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:58:12 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/27 20:58:12 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_print_hex(char *digits, int *pos)
{
	int		c;
	int		len;

	len = 0;
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

void	ft_percent_x(unsigned int n, int *pos, int is_upper)
{
	int		c;
	char	digits[16];
	char	*hex_table;

	if (is_upper)
		hex_table = "0123456789ABCDEF";
	else
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
	ft_print_hex(digits, pos);
}
