/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:58:15 by acarneir          #+#    #+#             */
/*   Updated: 2021/09/18 15:58:15 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_print_functions(const char *str, va_list arg, int *pos)
{
	if (*str == 'c')
		ft_percent_c(va_arg(arg, int), pos);
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		pos[1]++;
	}
	else if (*str == 's')
		ft_percent_s(va_arg(arg, char *), pos);
	else if (*str == 'd' || *str == 'i')
		ft_percent_di(va_arg(arg, int), pos);
	else if (*str == 'u')
		ft_percent_u(va_arg(arg, unsigned int), pos);
	else if (*str == 'x')
		ft_percent_x(va_arg(arg, unsigned int), pos, 0);
	else if (*str == 'X')
		ft_percent_x(va_arg(arg, unsigned int), pos, 1);
	else if (*str == 'p')
		ft_percent_p(va_arg(arg, unsigned long long int), pos);
	pos[0]++;
}

int	ft_printf(const char *str, ...)
{
	int		*pos;
	int		len;
	va_list	arg;

	va_start(arg, str);
	pos = ft_calloc(2, sizeof(int));
	while (str[pos[0]] != '\0')
	{
		if (str[pos[0]] == '%')
		{
			ft_print_functions(str + pos[0] + 1, arg, pos);
		}
		else
		{
			ft_putchar_fd(str[pos[0]], 1);
			pos[1]++;
		}
		pos[0]++;
	}
	va_end(arg);
	len = pos[1];
	free(pos);
	return (len);
}
