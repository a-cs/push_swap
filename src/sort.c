/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:45:58 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 22:30:17 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_push *push)
{
	if (push->stack_a[0] > push->stack_a[1])
	{
		if (push->op_list_size == 0)
		{
			push->op_list_size = 15;
			push->op_list = ft_calloc(push->op_list_size + 1, sizeof(int));
		}
		op_s('a', push->stack_a, push);
	}
}



void	sort(t_push *push)
{
	if (push->size == 2)
		sort_2(push);
	// if (push->size == 3)
	// 	sort_3(push);
	print_list(push);
}
