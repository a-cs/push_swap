/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:12:32 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 22:38:36 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sx(char c, int *stack, t_push *push)
{
	int	temp;

	if (get_stack_size(stack, push->size) > 1)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
		if (c == 'a')
			save_on_list(push, "sa");
		else if (c == 'b')
			save_on_list(push, "sb");
	}
}

void	op_rx(char c, int *stack, t_push *push)
{
	int	i;
	int	temp;

	if (get_stack_size(stack, push->size) > 1)
	{
		temp = stack[0];
		i = 0;
		while (i < get_stack_size(stack, push->size) - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = temp;
		if (c == 'a')
			save_on_list(push, "ra");
		else if (c == 'b')
			save_on_list(push, "rb");
	}
}

void	op_rrx(char c, int *stack, t_push *push)
{
	int	i;
	int	temp;

	if (get_stack_size(stack, push->size) > 1)
	{
		i = get_stack_size(stack, push->size) - 1;
		temp = stack[i];
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = temp;
		if (c == 'a')
			save_on_list(push, "rra");
		else if (c == 'b')
			save_on_list(push, "rrb");
	}
}

void	op_pb(t_push *push)
{
	int	i;
	int	temp;

	if (get_stack_size(push->stack_a, push->size) > 0)
	{
		temp = push->stack_a[0];
		i = 0;
		while (i < get_stack_size(push->stack_a, push->size) - 1)
		{
			push->stack_a[i] = push->stack_a[i + 1];
			i++;
		}
		push->stack_a[i] = 0;
		i = get_stack_size(push->stack_b, push->size);
		while (i > 0)
		{
			push->stack_b[i] = push->stack_b[i - 1];
			i--;
		}
		push->stack_b[i] = temp;
		save_on_list(push, "pb");
	}
}

void	op_pa(t_push *push)
{
	int	i;
	int	temp;

	if (get_stack_size(push->stack_b, push->size) > 0)
	{
		temp = push->stack_b[0];
		i = 0;
		while (i < get_stack_size(push->stack_b, push->size) - 1)
		{
			push->stack_b[i] = push->stack_b[i + 1];
			i++;
		}
		push->stack_b[i] = 0;
		i = get_stack_size(push->stack_a, push->size);
		while (i > 0)
		{
			push->stack_a[i] = push->stack_a[i - 1];
			i--;
		}
		push->stack_a[i] = temp;
		save_on_list(push, "pa");
	}
}
