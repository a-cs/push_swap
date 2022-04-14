/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:45:32 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/14 00:21:45 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static void	clear_args_and_print_error(char **args)
{
	clear_args(args);
	print_error();
}

void	is_valid_args_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && !((str[i] == '+' || str[i] == '-')
				&& ft_isdigit(str[i + 1])) && !ft_isdigit(str[i]))
		{
			ft_printf("str = %c%c\n", str[i], str[i + 1]);
			free(str);
			ft_printf("flag1 \n");
			print_error();
		}
		i++;
	}
}

void	is_valid_int(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			clear_args_and_print_error(args);
		else if (ft_strlen(args[i]) == 11
			&& ft_memcmp("-2147483648", args[i], 11) < 0)
			clear_args_and_print_error(args);
		else if (ft_strlen(args[i]) == 11 && args[i][0] == '+'
			&& ft_memcmp("+2147483647", args[i], 11) < 0)
			clear_args_and_print_error(args);
		else if (ft_strlen(args[i]) == 10
			&& ft_memcmp("2147483647", args[i], 10) < 0)
			clear_args_and_print_error(args);
		else if (ft_atoi(args[i]) == 0
			&& (ft_memcmp("+0", args[i], ft_strlen(args[i])) != 0
				&& ft_memcmp("-0", args[i], ft_strlen(args[i])) != 0
				&& ft_memcmp("0", args[i], ft_strlen(args[i])) != 0))
			clear_args_and_print_error(args);
		i++;
	}
}

void	has_duplicates(char **args)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (args[i])
	{
		value = ft_atoi(args[i]);
		j = i + 1;
		while (args[j])
		{
			if (value == ft_atoi(args[j]))
			{
				ft_printf("i = %d, arg[%d] = %d, v = %d\n", i, j, ft_atoi(args[j]), value);
				ft_printf("flag_d\n");
				clear_args_and_print_error(args);
			}
			j++;
		}
		i++;
	}
}
