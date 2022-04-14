/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:13:29 by acarneir          #+#    #+#             */
/*   Updated: 2022/04/14 00:27:24 by acarneir         ###   ########.fr       */
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
}	t_push;

void	print_error(void);
void	clear_args(char **args);
char	*get_args_str(int argc, char **argv);
void	is_valid_args_str(char *str);
void	is_valid_int(char **args);
void	has_duplicates(char **args);
void	normalize_stack(t_push *push);

#endif