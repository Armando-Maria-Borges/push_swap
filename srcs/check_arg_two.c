/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:39:09 by aborges           #+#    #+#             */
/*   Updated: 2024/08/06 16:35:09 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_arg_aux(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	ac = ft_check_param(stack_a, av);
	if (ac == 2)
		sort_two_stack(stack_a);
	if (ac == 3)
		sort_three_stack(stack_a);
	if (ac > 3)
	{
		if (ft_is_sorted(stack_a) == 1)
			return ;
		if (ft_stack_size(stack_a) <= 10)
			sort_min_value(stack_a, stack_b);
		sort_more_value(stack_a, stack_b);
	}
}

void	ft_check_arg(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	if (ac < 2)
		exit (0);
	if (ac == 2)
		ft_check_arg_aux(ac, av, stack_a, stack_b);
	else if (ac == 3)
	{
		ft_init_stack(stack_a, ac - 1, av + 1);
		sort_two_stack(stack_a);
	}
	else if (ac == 4)
	{
		ft_init_stack(stack_a, ac - 1, av + 1);
		sort_three_stack(stack_a);
	}
	else
	{
		ft_init_stack(stack_a, ac - 1, av + 1);
		if (ft_is_sorted(stack_a) == 1)
			return ;
		if (ft_stack_size(stack_a) <= 10)
			sort_min_value(stack_a, stack_b);
		sort_more_value(stack_a, stack_b);
	}
}
