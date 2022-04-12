/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:12:24 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/12 01:52:23 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
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
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		// if (str[i] != ' ' && !(str[i] == '+' && ft_isdigit(str[i + 1]))
		// 	&& !(str[i] == '-' && ft_isdigit(str[i + 1]))
		// 	&& !ft_isdigit(str[i]))
		if (str[i] != ' ' && !((str[i] == '+' || str[i] == '-')
				&& ft_isdigit(str[i + 1]))
			&& !ft_isdigit(str[i]))
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
			return (1);
		else if (ft_strlen(args[i]) == 11
			&& ft_memcmp("-2147483648", args[i], 11) < 0)
			return (1);
		else if (ft_strlen(args[i]) == 11 && args[i][0] == '+'
			&& ft_memcmp("+2147483647", args[i], 11) < 0)
			return (1);
		else if (ft_strlen(args[i]) == 10
			&& ft_memcmp("2147483647", args[i], 10) < 0)
			return (1);
		else if (ft_atoi(args[i]) == 0
			&& (ft_memcmp("+0", args[i], ft_strlen(args[i])) != 0
				&& ft_memcmp("-0", args[i], ft_strlen(args[i])) != 0
				&& ft_memcmp("0", args[i], ft_strlen(args[i])) != 0))
			return (1);
		i++;
	}
	return (0);
}

void	clear_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		// ft_printf("i -> %d args -> %s\n", i, args[i]);
		// ft_printf("str = %s -> atoi = %d\n", args[i], ft_atoi(args[i]));
		free(args[i]);
		i++;
	}
	free(args);
}

// pode receber "1 2 3" ou sem aspas
int	main(int argc, char **argv)
{
	char	**args;
	char	*args_str;
	int		flag2;
	// ft_printf("+-42 %d\n" ,ft_atoi("+-42"));
	// ft_strncmp(str, "0", ft_strlen(str))

	if (argc >= 2)
	{
		args_str = get_args_str(argc, argv);
		is_valid_args_str(args_str);
		args = ft_split(args_str, ' ');
		flag2 = is_valid_int(args);
		clear_args(args);
		// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./push_swap "1 2" "3 4 5"  "+-1"
		ft_printf("args_str -> %s\n", args_str);
		free(args_str);
		ft_printf("flag2 -> %d\n", flag2);
		if (flag2)
			print_error();
	}

	return (0);
}
