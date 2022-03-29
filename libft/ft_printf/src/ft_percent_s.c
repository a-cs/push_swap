/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:51:15 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/25 21:51:15 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_percent_s(char *arg, int *pos)
{
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		pos[1] += 6;
	}
	else
	{
		ft_putstr_fd(arg, 1);
		pos[1] += ft_strlen(arg);
	}
}
