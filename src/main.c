/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:12:24 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/13 18:37:21 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

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

char	*get_args_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*old_str;
	char	*new_str;

	new_str = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		old_str = new_str;
		str = ft_strjoin(" ", argv[i]);
		new_str = ft_strjoin(old_str, str);
		free(old_str);
		free(str);
		i++;
	}
	return (new_str);
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

int	is_valid_int(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			return (0);
		else if (ft_strlen(args[i]) == 11
			&& ft_memcmp("-2147483648", args[i], 11) < 0)
			return (0);
		else if (ft_strlen(args[i]) == 11 && args[i][0] == '+'
			&& ft_memcmp("+2147483647", args[i], 11) < 0)
			return (0);
		else if (ft_strlen(args[i]) == 10
			&& ft_memcmp("2147483647", args[i], 10) < 0)
			return (0);
		else if (ft_atoi(args[i]) == 0
			&& (ft_memcmp("+0", args[i], ft_strlen(args[i])) != 0
				&& ft_memcmp("-0", args[i], ft_strlen(args[i])) != 0
				&& ft_memcmp("0", args[i], ft_strlen(args[i])) != 0))
			return (0);
		i++;
	}
	return (1);
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
				clear_args(args);
				ft_printf("flag_d\n");
				print_error();
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	char	*args_str;

	if (argc >= 2)
	{
		args_str = get_args_str(argc, argv);
		ft_printf("args_str -> %s\n", args_str);
		is_valid_args_str(args_str);
		args = ft_split(args_str, ' ');
		free(args_str);
		if (is_valid_int(args))
		{
			has_duplicates(args);
			ft_printf("OK");
			clear_args(args);
		}
		else
		{
			clear_args(args);
			ft_printf("flag_int\n");
			print_error();
		}
	}
	return (0);
}
