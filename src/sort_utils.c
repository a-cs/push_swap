/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:59:42 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/16 00:10:43 by acarneir         ###   ########.fr       */
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
			op_rx(c, push->stack_a, push);
	else
		while (stack[0] != value)
			op_rrx(c, push->stack_a, push);
}
