/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:47:23 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/25 22:47:23 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_percent_di(int arg, int *pos)
{
	char	*num;

	num = ft_itoa(arg);
	ft_putstr_fd(num, 1);
	pos[1] += ft_strlen(num);
	free(num);
}
