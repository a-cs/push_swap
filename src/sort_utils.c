/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:59:42 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/16 19:09:41 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bring_to_top(int *stack, t_push *push, int pos, char c)
{
	int	value;
	int	stack_size;

	stack_size = get_stack_size(stack, push->size);
	value = stack[pos];
	if (pos < stack_size / 2)
		while (stack[0] != value)
			op_rx(c, stack, push);
	else
		while (stack[0] != value)
			op_rrx(c, stack, push);
}

static int	counter_rrx(int *stack, t_push *push)
{
	int	i;
	int	temp;
	int	counter;

	if (get_stack_size(stack, push->size) > 1)
	{
		i = get_stack_size(stack, push->size) - 1;
		temp = stack[i];
		counter = 0;
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = temp;
		counter++;
		return (counter);
	}
	return (0);
}

static int	counter_rx(int *stack, t_push *push)
{
	int	i;
	int	temp;
	int	counter;

	if (get_stack_size(stack, push->size) > 1)
	{
		temp = stack[0];
		i = 0;
		counter = 0;
		while (i < get_stack_size(stack, push->size) - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = temp;
		counter++;
		return (counter);
	}
	return (0);
}

int	distance_to_top(int *stack, t_push *push, int pos)
{
	int	distance;
	int	value;
	int	stack_size;

	stack_size = get_stack_size(stack, push->size);
	value = stack[pos];
	distance = 0;
	if (stack_size / 2 != 0)
	{
		if (pos > stack_size / 2)
			while (stack[0] != value)
				distance += counter_rrx(stack, push);
		else
			while (stack[0] != value)
				distance += counter_rx(stack, push);
	}
	return (distance);
}
