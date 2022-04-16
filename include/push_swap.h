/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:13:29 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/16 19:56:16 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"

typedef struct s_push
{
	int	size;
	int	*stack_a;
	int	*stack_b;
	int	op_list_size;
	int	*op_list;
}	t_push;

void	print_error(void);
void	clear_args(char **args);
char	*get_args_str(int argc, char **argv);
void	is_valid_args_str(char *str);
void	is_valid_int(char **args);
void	has_duplicates(char **args);
void	initialize_push(char **args, t_push *push);
void	clear_push(t_push *push);
int		get_biggest_pos(int *stack, int size);
int		get_smallest_pos(int *stack, int size);
void	normalize_stack(t_push *push);
int		get_stack_size(int *stack, int real_size);
int		is_sorted(t_push *push);
void	sort(t_push *push);
void	op_sx(char c, int *stack, t_push *push);
void	op_rx(char c, int *stack, t_push *push);
void	op_rrx(char c, int *stack, t_push *push);
void	op_pb(t_push *push);
void	op_pa(t_push *push);
void	save_on_list(t_push *push, char *op);
void	print_list(t_push *push);
void	bring_to_top(int *stack, t_push *push, int pos, char c);
void	quick_sort(t_push *push, int pivot);
int		distance_to_top(int *stack, t_push *push, int pos);
void	copy_push(t_push *push2, t_push *push);
void	get_nearest_pos(int *pos, t_push *push, int min, int max);
int		get_index(int *stack, int size, int value);

#endif