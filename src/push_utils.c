/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:15:28 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 22:32:04 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_push(t_push *push)
{
	if (push->stack_a != NULL)
		free(push->stack_a);
	if (push->stack_b != NULL)
		free(push->stack_b);
	if (push->op_list != NULL)
		free(push->op_list);
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
	// ft_printf("size = %d\n", push->size);
	i = 0;
	while (i < push->size)
	{
		push->stack_a[i] = ft_atoi(args[i]);
		// ft_printf("a[%d] = %d\n", i, push->stack_a[i]);
		i++;
	}
	normalize_stack(push);
}

int	get_stack_size(int *stack, int real_size)
{
	int	size;

	size = 0;
	while (size < real_size && stack[size] != 0)
		size++;
	return (size);
}

int	is_sorted(t_push *push)
{
	int	i;
	int	j;
	int	stack_size;
	int	value;

	if (get_stack_size(push->stack_b, push->size) != 0)
		return (0);
	i = 0;
	stack_size = get_stack_size(push->stack_a, push->size);
	while (i < push->size)
	{
		value = push->stack_a[i];
		j = i + 1;
		while (j < stack_size)
		{
			if (value > push->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
