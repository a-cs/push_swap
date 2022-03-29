/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:35:48 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/27 17:35:48 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_percent_u(unsigned int n, int *pos)
{
	int		c;
	int		len;
	char	digits[11];

	c = -1;
	while (++c <= 10)
	{
		if (c > 0 && n == 0)
			digits[c] = 'x';
		else
			digits[c] = n % 10 + '0';
		n /= 10;
	}
	len = 0;
	c = 10;
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
