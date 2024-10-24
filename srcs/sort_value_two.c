/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_value_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:39:47 by aborges           #+#    #+#             */
/*   Updated: 2024/08/06 16:43:36 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_min_node(t_list **stack, t_min_info *info)
{
	t_list	*tmp;

	tmp = *stack;
	info->min_node = tmp;
	info->min_value = tmp->value;
	info->len_stack = 0;
	info->len_position_min = 0;
	while (tmp != NULL)
	{
		if (tmp->value > info->min_value)
		{
			info->min_value = tmp->value;
			info->min_node = tmp;
			info->len_position_min = info->len_stack;
		}
		tmp = tmp->next;
		info->len_stack++;
	}
}

void	move_min_node_to_top(t_list **stack_b, t_min_info *info)
{
	while (*stack_b != info->min_node)
	{
		if ((info->len_stack - info->len_position_min) >= (info->len_stack / 2))
		{
			if ((*stack_b)->next == info->min_node)
			{
				ft_sb(stack_b);
			}
			else if ((*stack_b)->next->next == info->min_node)
			{
				ft_rb(stack_b);
				ft_sb(stack_b);
			}
			else
			{
				ft_rb(stack_b);
			}
		}
		else
		{
			ft_rrb(stack_b);
		}
	}
}

void	ft_check_min_position(t_list **stack_a, t_list **stack_b)
{
	t_min_info	info;

	if (*stack_b == NULL)
		return ;
	find_min_node(stack_b, &info);
	if (*stack_b == info.min_node)
	{
		ft_pa(stack_a, stack_b);
	}
	else
	{
		move_min_node_to_top(stack_b, &info);
		ft_pa(stack_a, stack_b);
	}
}

void	send_partition(t_list **stack_a, t_list **stack_b, int partition)
{
	int		part;
	int		big;
	int		i;

	big = find_max_value(stack_a) / partition;
	part = big;
	while (part <= (big * partition))
	{
		i = -1;
		while (++i <= ft_stack_size(stack_a))
		{
			if ((*stack_a)->value <= part)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		part += big;
	}
}

void	sort_more_value(t_list **stack_a, t_list **stack_b)
{
	int	count_pa;
	int	result;

	if (ft_is_sorted(stack_a))
		return ;
	result = (((8 - (ft_stack_size(stack_a) / 100)) * (ft_stack_size(stack_a)
					/ 100)));
	if (result < 1)
		result = 1;
	send_partition(stack_a, stack_b, result);
	while (ft_stack_size(stack_a) > 0)
		ft_pb(stack_a, stack_b);
	count_pa = 0;
	while (ft_stack_size(stack_b) > 0)
	{
		ft_check_min_position(stack_a, stack_b);
		count_pa++;
	}
	while (count_pa > 0)
	{
		ft_pa(stack_a, stack_b);
		count_pa--;
	}
}
