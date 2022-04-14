/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:12:24 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/14 00:27:58 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	clear_push(t_push *push)
{
	if (push->stack_a != NULL)
		free(push->stack_a);
	if (push->stack_b != NULL)
		free(push->stack_b);
	if (push != NULL)
		free(push);
}

void	initialize_push(char **args, t_push *push)
{
	int	i;

	i = 0;
	while (args[i])
	{
		i++;
	}
	push->size = i;
	push->stack_a = ft_calloc(push->size, sizeof(int));
	push->stack_b = ft_calloc(push->size, sizeof(int));
	ft_printf("size = %d\n", push->size);
	i = 0;
	while (i < push->size)
	{
		push->stack_a[i] = ft_atoi(args[i]);
		ft_printf("a[%d] = %d\n", i, push->stack_a[i]);
		i++;
	}
	normalize_stack(push);
}

int	main(int argc, char **argv)
{
	char	**args;
	char	*args_str;
	t_push	*push;

	if (argc >= 2)
	{
		args_str = get_args_str(argc, argv);
		ft_printf("args_str -> %s\n", args_str);
		is_valid_args_str(args_str);
		args = ft_split(args_str, ' ');
		free(args_str);
		is_valid_int(args);
		has_duplicates(args);
		push = ft_calloc(1, sizeof(t_push));
		initialize_push(args, push);
		clear_args(args);
		clear_push(push);
	}
	return (0);
}
