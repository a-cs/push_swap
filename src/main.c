/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:12:24 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 22:29:55 by acarneir         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**args;
	char	*args_str;
	t_push	*push;

	if (argc >= 2)
	{
		args_str = get_args_str(argc, argv);
		// ft_printf("args_str -> %s\n", args_str);
		is_valid_args_str(args_str);
		args = ft_split(args_str, ' ');
		free(args_str);
		is_valid_int(args);
		has_duplicates(args);
		push = ft_calloc(1, sizeof(t_push));
		initialize_push(args, push);
		clear_args(args);
		if (!is_sorted(push))
			sort(push);
		clear_push(push);
	}
	return (0);
}
