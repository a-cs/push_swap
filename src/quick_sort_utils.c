/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:47:36 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/16 19:49:32 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	copy_push(t_push *push2, t_push *push)
{
	int	i;

	push2->size = push->size;
	push2->stack_a = ft_calloc(push->size + 1, sizeof(int *));
	push2->stack_b = ft_calloc(push->size + 1, sizeof(int *));
	push2->op_list = NULL;
	push2->op_list_size = 0;
	i = 0;
	while (i < push->size)
	{
		if (push->stack_a[i] != 0)
			push2->stack_a[i] = push->stack_a[i];
		if (push->stack_b[i] != 0)
			push2->stack_b[i] = push->stack_b[i];
		i++;
	}
}

void	get_nearest_pos(int *pos, t_push *push, int min, int max)
{
	int	i;

	i = 0;
	pos[0] = -1;
	pos[1] = -1;
	while (i < push->size && (pos[0] == -1 || pos[1] == -1))
	{
		if (push->stack_a[i] != 0 && push->stack_a[i] >= min
			&& push->stack_a[i] < max && pos[0] == -1)
			pos[0] = i;
		if (push->stack_a[push->size - 1 - i] != 0
			&& push->stack_a[push->size - 1 - i] >= min
			&& push->stack_a[push->size - 1 - i] < max && pos[1] == -1)
			pos[1] = push->size - 1 - i;
		i++;
	}
}

int	get_index(int *stack, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
