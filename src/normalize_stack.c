/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:26:29 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 20:05:41 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_biggest_pos(int *stack, int size)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		if (stack[i] > stack[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static int	get_smallest_pos(int *stack, int size)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		if (stack[i] < stack[pos])
			pos = i;
		i++;
	}
	return (pos);
}

void	normalize_stack(t_push *push)
{
	int	i;
	int	pos;

	pos = get_biggest_pos(push->stack_a, push->size);
	push->stack_b[pos] = push->size;
	i = 1;
	while (i < push->size)
	{
		pos = get_smallest_pos(push->stack_a, push->size);
		push->stack_b[pos] = i;
		push->stack_a[pos] = 2147483647;
		i++;
	}
	i = 0;
	while (i < push->size)
	{
		push->stack_a[i] = push->stack_b[i];
		push->stack_b[i] = 0;
		// ft_printf("a[%d] = %d\tb[%d] = %d\n", i, push->stack_a[i], i, push->stack_b[i]);
		i++;
	}
}
