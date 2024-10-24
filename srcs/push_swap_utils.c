/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:49:02 by aborges           #+#    #+#             */
/*   Updated: 2024/08/06 16:43:25 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_size(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_max_value(t_list **stack)
{
	int		big;
	t_list	*tmp;

	tmp = *stack;
	big = tmp->value;
	while (tmp)
	{
		if (tmp->value > big)
			big = tmp->value;
		tmp = tmp->next;
	}
	return (big);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	ft_display_error(t_list **stack_a)
{
	ft_free_stack(stack_a);
	write(1, "Error\n", 6);
	exit(0);
}
