/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:13:53 by aborges           #+#    #+#             */
/*   Updated: 2024/08/02 04:43:01 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	write(1, "ss\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_a;
	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	tmp = *stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack_b;
	tmp = (*stack_b);
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	second_last = *stack_a;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	second_last = *stack_b;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrr\n", 4);
}
