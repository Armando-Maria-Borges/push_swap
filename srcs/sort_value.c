/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:25:55 by aborges           #+#    #+#             */
/*   Updated: 2024/08/05 01:45:35 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_two_stack(t_list **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	if ((*stack)->value > (*stack)->next->value)
		ft_sa(stack);
	else
		return ;
}

void	sort_three_stack_aux(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	tmp = tmp->next;
	if (!(*stack) || !(*stack)->next)
		return ;
	if ((*stack)->value > (*stack)->next->value)
	{
		ft_sa(stack);
	}
	else if (((*stack)->value > (*stack)->next->value)
		&& ((*stack)->value > tmp->next->value))
	{
		ft_ra(stack);
	}
	else if (((*stack)->value < (*stack)->next->value)
		&& ((*stack)->value > tmp->next->value))
	{
		ft_rra(stack);
	}
	else if (((*stack)->value < (*stack)->next->value)
		&& ((*stack)->value < tmp->next->value))
	{
		ft_rra(stack);
	}
}

void	sort_three_stack(t_list **stack)
{
	int		sort;

	if (!(*stack) || !(*stack)->next)
		return ;
	sort = ft_is_sorted(stack);
	while (sort == 0)
	{
		sort_three_stack_aux(stack);
		sort = ft_is_sorted(stack);
	}
}
