/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:45:58 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 23:28:11 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_2(t_push *push)
{
	if (push->stack_a[0] > push->stack_a[1])
	{
		if (push->op_list_size == 0)
		{
			push->op_list_size = 15;
			push->op_list = ft_calloc(push->op_list_size + 1, sizeof(int));
		}
		op_sx('a', push->stack_a, push);
	}
}

static void	sort_3(t_push *push)
{
	if (push->op_list_size == 0)
	{
		push->op_list_size = 15;
		push->op_list = ft_calloc(push->op_list_size + 1, sizeof(int));
	}
	if (push->stack_a[2] > push->stack_a[1]
		&& push->stack_a[2] > push->stack_a[0])
		op_sx('a', push->stack_a, push);
	else if (push->stack_a[2] < push->stack_a[1]
		&& push->stack_a[2] < push->stack_a[0])
	{
		if (push->stack_a[1] < push->stack_a[0])
			op_sx('a', push->stack_a, push);
		op_rrx('a', push->stack_a, push);
	}
	else
	{
		if (push->stack_a[1] > push->stack_a[0])
			op_sx('a', push->stack_a, push);
		op_rx('a', push->stack_a, push);
	}
}



void	sort(t_push *push)
{
	if (push->size == 2)
		sort_2(push);
	if (push->size == 3)
		sort_3(push);
	print_list(push);
}
