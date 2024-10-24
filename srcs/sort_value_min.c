/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_value_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:39:47 by aborges           #+#    #+#             */
/*   Updated: 2024/08/05 21:03:53 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_min_node_two(t_list *stack, t_min_info *info)
{
	t_list	*tmp;

	tmp = stack;
	info->min_node = tmp;
	info->min_value = tmp->value;
	info->len_stack = 0;
	info->len_position_min = 0;
	while (tmp != NULL)
	{
		if (tmp->value < info->min_value)
		{
			info->min_value = tmp->value;
			info->min_node = tmp;
			info->len_position_min = info->len_stack;
		}
		tmp = tmp->next;
		info->len_stack++;
	}
}

void	move_min_node_to_top_two(t_list **stack_a, t_min_info *info)
{
	while (*stack_a != info->min_node)
	{
		if ((info->len_stack - info->len_position_min) >= (info->len_stack / 2))
		{
			if ((*stack_a)->next == info->min_node)
			{
				ft_sa(stack_a);
			}
			else if ((*stack_a)->next->next == info->min_node)
			{
				ft_ra(stack_a);
				ft_sa(stack_a);
			}
			else
			{
				ft_ra(stack_a);
			}
		}
		else
		{
			ft_rra(stack_a);
		}
	}
}

void	ft_check_min_position_two(t_list **stack_a, t_list **stack_b)
{
	t_min_info	info;

	if (*stack_a == NULL)
		return ;
	find_min_node_two(*stack_a, &info);
	if (*stack_a == info.min_node)
	{
		ft_pb(stack_a, stack_b);
	}
	else
	{
		move_min_node_to_top_two(stack_a, &info);
		ft_pb(stack_a, stack_b);
	}
}

void	sort_min_value(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	count_pb;

	if (ft_is_sorted(stack_a))
		exit (0);
	len = ft_stack_size(stack_a);
	count_pb = 0;
	while (len > 3)
	{
		ft_check_min_position_two(stack_a, stack_b);
		count_pb++;
		len = ft_stack_size(stack_a);
	}
	sort_three_stack(stack_a);
	while (count_pb > 0)
	{
		ft_pa(stack_a, stack_b);
		count_pb--;
	}
}
