/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:13:29 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/15 22:38:48 by acarneir         ###   ########.fr       */
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

#endif