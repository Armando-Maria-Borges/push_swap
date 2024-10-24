/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:13:28 by aborges           #+#    #+#             */
/*   Updated: 2024/08/05 20:56:46 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_min_info
{
	t_list	*min_node;
	int		min_value;
	int		len_stack;
	int		len_position_min;
}				t_min_info;

void	sort_min_value(t_list **stack_a, t_list **stack_b);
int		find_max_value(t_list **stack);
void	ft_sort(t_list **stack_a);
void	sort(t_list **stack_a, t_list **stack_b);
int		ft_stack_size1(t_list *stack);

void	ft_check_arg(int ac, char **av, t_list **stack_a, t_list **stack_b);
void	ft_init_stack(t_list **stack_a, int argc, char **argv);
void	ft_display_error(t_list **stack_a);
void	ft_free_stack(t_list **stack);
int		ft_atoi(const char *str);
int		ft_atoi_stack(const char *str, t_list **stack_a);
int		ft_is_sorted(t_list **stack);
int		ft_check_maxmin_int(long av);
char	**ft_simple_split(char *str);
void	skip_whitespace(char **str);
void	copy_word(char *dest, char **src);
int		ft_equal_value(char **av, int position);
int		ft_check_param(t_list **stack_a, char **av);
int		ft_search_space(char *s, char c);
int		ft_check_only_number(char **av);

void	ft_print_stack(t_list **stack);
void	ft_print_stacks(t_list **stack_a, t_list **stack_b);
int		ft_stack_size(t_list **stack);

void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

void	sort_two_stack(t_list **stack);
void	sort_three_stack(t_list **stack);
void	sort_more_value(t_list **stack_a, t_list **stack_b);

#endif
