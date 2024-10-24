/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:13:44 by aborges           #+#    #+#             */
/*   Updated: 2024/08/05 17:55:11 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_a;
	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_b;
	tmp = (*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	second_last = *stack_a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	second_last = *stack_b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
