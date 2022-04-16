/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:06:53 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 22:23:27 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	save_on_list(t_push *push, char *op)
{
	int	pos;

	pos = get_stack_size(push->op_list, push->op_list_size);
	if (ft_memcmp(op, "sa", ft_strlen(op)) == 0)
		push->op_list[pos] = 1;
	else if (ft_memcmp(op, "sb", ft_strlen(op)) == 0)
		push->op_list[pos] = 2;
	else if (ft_memcmp(op, "ss", ft_strlen(op)) == 0)
		push->op_list[pos] = 3;
	else if (ft_memcmp(op, "ra", ft_strlen(op)) == 0)
		push->op_list[pos] = 4;
	else if (ft_memcmp(op, "rb", ft_strlen(op)) == 0)
		push->op_list[pos] = 5;
	else if (ft_memcmp(op, "rr", ft_strlen(op)) == 0)
		push->op_list[pos] = 6;
	else if (ft_memcmp(op, "rra", ft_strlen(op)) == 0)
		push->op_list[pos] = 7;
	else if (ft_memcmp(op, "rrb", ft_strlen(op)) == 0)
		push->op_list[pos] = 8;
	else if (ft_memcmp(op, "rrr", ft_strlen(op)) == 0)
		push->op_list[pos] = 9;
	else if (ft_memcmp(op, "pa", ft_strlen(op)) == 0)
		push->op_list[pos] = 10;
	else if (ft_memcmp(op, "pb", ft_strlen(op)) == 0)
		push->op_list[pos] = 11;
}

static void	print_list_item(int op)
{
	if (op == 1)
		ft_printf("sa\n");
	else if (op == 2)
		ft_printf("sb\n");
	else if (op == 3)
		ft_printf("ss\n");
	else if (op == 4)
		ft_printf("ra\n");
	else if (op == 5)
		ft_printf("rb\n");
	else if (op == 6)
		ft_printf("rr\n");
	else if (op == 7)
		ft_printf("rra\n");
	else if (op == 8)
		ft_printf("rrb\n");
	else if (op == 9)
		ft_printf("rrr\n");
	else if (op == 10)
		ft_printf("pa\n");
	else if (op == 11)
		ft_printf("pb\n");
}

void	print_list(t_push *push)
{
	int	i;

	i = 0;
	while (i < push->op_list_size)
	{
		print_list_item(push->op_list[i]);
		i++;
	}
}
