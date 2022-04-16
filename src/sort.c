/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:45:58 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/16 01:02:49 by acarneir         ###   ########.fr       */
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

static void	sort_4(t_push *push)
{
	int	i;

	if (push->op_list_size == 0)
	{
		push->op_list_size = 15;
		push->op_list = ft_calloc(push->op_list_size + 1, sizeof(int));
	}
	i = 0;
	while (i < 2)
	{
		bring_to_top(push->stack_a, push, get_smallest_pos(push->stack_a,
				get_stack_size(push->stack_a, push->size)), 'a');
		op_pb(push);
		i++;
	}
	sort_2(push);
	op_pa(push);
	op_pa(push);
}

static void	sort_5(t_push *push)
{
	int	i;

	if (push->op_list_size == 0)
	{
		push->op_list_size = 15;
		push->op_list = ft_calloc(push->op_list_size + 1, sizeof(int));
	}
	i = 0;
	while (i < 2)
	{
		bring_to_top(push->stack_a, push, get_smallest_pos(push->stack_a,
				get_stack_size(push->stack_a, push->size)), 'a');
		op_pb(push);
		i++;
	}
	if (!(push->stack_a[0] < push->stack_a[1]
			&& push->stack_a[1] < push->stack_a[2]))
		sort_3(push);
	op_pa(push);
	op_pa(push);
}



void	sort(t_push *push)
{
	if (push->size == 2)
		sort_2(push);
	if (push->size == 3)
		sort_3(push);
	if (push->size == 4)
		sort_4(push);
	if (push->size == 5)
		sort_5(push);
	print_list(push);
}
