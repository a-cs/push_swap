/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:35:21 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/24 22:35:21 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_percent_c(int arg, int *pos)
{
	unsigned char	c;

	c = (unsigned char) arg;
	ft_putchar_fd(c, 1);
	pos[1]++;
}
