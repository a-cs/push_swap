/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:08:52 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/16 19:59:39 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	update_window(int *pivot_window, int pivot, t_push *push)
{
	pivot_window[0] += push->size / pivot;
	pivot_window[2] += push->size / pivot;
	pivot_window[1] = (pivot_window[0] + pivot_window[2]) / 2;
}

static void	send_to_a2(int *pos, t_push *push, t_push *push2, t_push *push3)
{
	if (pos[2] > 1 && distance_to_top(push2->stack_b, push2, pos[0])
		< distance_to_top(push3->stack_b, push3, pos[1]))
	{
		bring_to_top(push->stack_b, push, pos[0], 'b');
		op_pa(push);
	}
	else if (pos[2] > 1)
	{
		bring_to_top(push->stack_b, push, pos[1], 'b');
		op_pa(push);
		bring_to_top(push->stack_b, push, get_index(push->stack_b,
				push->size, pos[2]), 'b');
		op_pa(push);
		op_sx('a', push->stack_a, push);
		pos[2]--;
	}
	else if (pos[2] == 1)
		op_pa(push);
}

static void	send_to_a(int *pos, t_push *push)
{
	t_push	*push2;
	t_push	*push3;

	pos[0] = get_index(push->stack_b, push->size, pos[2]);
	pos[1] = get_index(push->stack_b, push->size, pos[2] - 1);
	push2 = malloc(sizeof(t_push));
	push3 = malloc(sizeof(t_push));
	copy_push(push2, push);
	copy_push(push3, push);
	send_to_a2(pos, push, push2, push3);
	clear_push(push2);
	clear_push(push3);
}

static void	send_to_b(t_push *push, int *pos, int *pivot_window)
{
	t_push	*push2;
	t_push	*push3;

	push2 = malloc(sizeof(t_push));
	push3 = malloc(sizeof(t_push));
	copy_push(push2, push);
	copy_push(push3, push);
	get_nearest_pos(pos, push, pivot_window[0], pivot_window[2]);
	if (distance_to_top(push2->stack_a, push2, pos[0])
		< distance_to_top(push3->stack_a, push3, pos[1]))
		bring_to_top(push->stack_a, push, pos[0], 'a');
	else
		bring_to_top(push->stack_a, push, pos[1], 'a');
	op_pb(push);
	if (get_stack_size(push->stack_b, push->size) > 1
		&& push->stack_b[0] < pivot_window[1])
		op_rx('b', push->stack_b, push);
	clear_push(push2);
	clear_push(push3);
}

void	quick_sort(t_push *push, int pivot)
{
	int	*pivot_window;
	int	*pos;

	pos = ft_calloc(3, sizeof(int));
	pivot_window = ft_calloc(3, sizeof(int));
	pivot_window[0] = 1;
	pivot_window[1] = push->size / pivot / 2;
	pivot_window[2] = push->size / pivot + 1;
	while (pos[2] < push->size)
	{
		send_to_b(push, pos, pivot_window);
		pos[2]++;
		if (pos[2] == pivot_window[2] - 1)
			update_window(pivot_window, pivot, push);
	}
	pos[2] = push->size;
	while (pos[2] > 0)
	{
		send_to_a(pos, push);
		pos[2]--;
	}
	free(pos);
	free(pivot_window);
}
